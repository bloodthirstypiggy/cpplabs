#include <string>
#include "main.h"

#define DAMAGE_BY_ENEMY 10;

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
void EnableOpenGL(HWND hwnd, HDC*, HGLRC*);
void DisableOpenGL(HWND, HDC, HGLRC);

// GRAPHICS FUNCS
void glGameInit()
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void printString(float x, float y, char* text, float r, float g, float b)
{
	static char buffer[99999]; // ~500 chars
	int num_quads;

	num_quads = stb_easy_font_print(x, y, text, NULL, buffer, sizeof(buffer));

	//glColor3f(r, g, b);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(2, GL_FLOAT, 16, buffer);
	glDrawArrays(GL_QUADS, 0, num_quads * 4);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void drawSquare(float size, float x, float y)
{
	glDisable(GL_TEXTURE_2D);
	float vertex[] = { x,y,0, x + size,y,0, x + size,y + size,0, x,y + size,0 };

	glPushMatrix();
	glEnableClientState(GL_VERTEX_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, vertex);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

	glDisableClientState(GL_VERTEX_ARRAY);
	glPopMatrix();
}

void drawEnemy(Enemy& enemy, float size)
{
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);  drawSquare(Map::sizeOfSquare, enemy.getCoord().x, enemy.getCoord().y);
	for (auto i = enemy.getEffectList().begin(); i != enemy.getEffectList().end(); i++)
	{
		switch ((*i).effect->getEffetType())
		{
		case EffectType::damageIncrease:
			glColor4f(1.0f, 0.0f, 0.0f, 0.2f);
			drawSquare(Map::sizeOfSquare, enemy.getCoord().x, enemy.getCoord().y);
			break;
		case EffectType::poisoning:
			glColor4f(0.0f, 1.0f, 0.0f, 0.2f);
			drawSquare(Map::sizeOfSquare, enemy.getCoord().x, enemy.getCoord().y);
			break;
		case EffectType::slow:
			glColor4f(0.0f, 0.0f, 1.0f, 0.2f);
			drawSquare(Map::sizeOfSquare, enemy.getCoord().x, enemy.getCoord().y);

			break;
		}
	}
	glLineWidth(4);
	glBegin(GL_LINES);
	glColor4f(0, 0.7f, 0, 1.0f);
	glVertex2f(enemy.getCoord().x, enemy.getCoord().y + size);
	glVertex2f(enemy.getCoord().x + size, enemy.getCoord().y + size);
	glColor4f(0, 1.0f, 0, 1.0f);
	glVertex2f(enemy.getCoord().x, enemy.getCoord().y + size);
	glVertex2f((enemy.getCoord().x + size * enemy.getCurHp() / enemy.getMaxHp()), enemy.getCoord().y + size);
	glEnd();
	glLineWidth(1);
	glColor4f(1, 1, 1, 1.0f);
}

void printText(std::string text, float x, float y, float resizeCoeff)
//ŒÚ -1 ‰Ó 1 ÛÍ‡Á˚‚‡Ú¸.
{
	float k = (float)Map::w / (float)Map::h;
	float h = (x / k + 1.0f) * (Map::w / 2.0f);
	float w = (1.0f - y) * (Map::h / 2.0f);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0, Map::w, Map::h, 0, -1, 1);
	const char* c = (text.c_str());
	char* cString = new char[text.size() + 1];
	int i = 0;
	while (*c)
	{
		cString[i] = *(c++);
		i++;
	}
	cString[i] = '\0';
	glScalef(resizeCoeff, resizeCoeff, 1.0f);
	printString(h / resizeCoeff, w / resizeCoeff, cString, 1.0f, 1.0f, 1.0f);
	delete[] cString;
	glPopMatrix();
}

void drawCell()
{
	float toY = Map::mapFromY + (GameMap::getMapSizeY()) * Map::sizeOfSquare;
	float toX = Map::mapFromX + (GameMap::getMapSizeX()) * Map::sizeOfSquare;
	for (int i = 0; i < GameMap::getMapSizeX() + 1; i++)
	{
		glBegin(GL_LINES);
		glVertex2f(Map::mapFromX + Map::sizeOfSquare * i, Map::mapFromY);
		glVertex2f(Map::mapFromX + Map::sizeOfSquare * i, toY);
		glEnd();
	}
	for (int j = 0; j < GameMap::getMapSizeY() + 1; j++)
	{
		glBegin(GL_LINES);
		glVertex2f(Map::mapFromX, Map::mapFromY + Map::sizeOfSquare * j);
		glVertex2f(toX, Map::mapFromY + Map::sizeOfSquare * j);
		glEnd();
	}
}

void drawMap()
{
	for (int i = 0; i < GameMap::getMapSizeX(); i++)
	{
		for (int j = 0; j < GameMap::getMapSizeY(); j++)
		{
			switch (GameMap::getMap().find(std::pair<int, int>(i, j))->second.field.getFieldType())
			{
			case FieldType::empty:
				glColor3f(0.1f, 0.5f, 0.1f);
				break;
			case FieldType::forest:
				glColor3f(0, 1.0f, 0);
				break;
			case FieldType::road:
				glColor3f(0.57f, 0.36f, 0.21f);
				break;
			}
			drawSquare(Map::sizeOfSquare, Map::mapFromX + i * Map::sizeOfSquare, Map::mapFromY + j * Map::sizeOfSquare);
			if (GameMap::getMap().find(std::pair<int, int>(i, j))->second.building != nullptr)
			{
				switch (GameMap::getMap().find(std::pair<int, int>(i, j))->second.building->getEnvironmentType())
				{
				case EnvironmentType::castle:
					glColor3f(1, 0.87f, 0.42f);
					drawSquare(Map::sizeOfSquare, Map::mapFromX + i * Map::sizeOfSquare, Map::mapFromY + j * Map::sizeOfSquare);
					break;
				case EnvironmentType::emenySpawner:
					glColor3f(0.14f, 0.12f, 0.04f);
					drawSquare(Map::sizeOfSquare, Map::mapFromX + i * Map::sizeOfSquare, Map::mapFromY + j * Map::sizeOfSquare);
					break;
				case EnvironmentType::tower:
					//glColor3f(0.14f, 0.12f, 0.04f);
					//drawSquare(Map::sizeOfSquare, Map::mapFromX + i * Map::sizeOfSquare, Map::mapFromY + j * Map::sizeOfSquare);
					dynamic_cast<Tower*>(GameMap::getMap().find(std::pair<int, int>(i, j))->second.building)->draw(Map::sizeOfSquare, Map::mapFromX + i * Map::sizeOfSquare, Map::mapFromY + j * Map::sizeOfSquare);
					break;
				case EnvironmentType::trap:
					dynamic_cast<Trap*>(GameMap::getMap().find(std::pair<int, int>(i, j))->second.building)->draw(Map::sizeOfSquare, Map::mapFromX + i * Map::sizeOfSquare, Map::mapFromY + j * Map::sizeOfSquare);
					break;
				}
			}
		}
	}
	glColor3f(1, 0.87f, 0.42f); drawSquare(Map::sizeOfSquare, Map::mapFromX + GameMap::getCastle().getCoord().x * Map::sizeOfSquare, Map::mapFromY + GameMap::getCastle().getCoord().y * Map::sizeOfSquare);
	glColor3f(1, 1, 1);  drawCell();
}

Coord getMapCoordByCursor(float x, float y)
{
	if (!(Map::mapFromX < x && Map::mapToX > x && Map::mapFromY < y && Map::mapToY > y))
		return Coord(-1, -1);
	FloatCoord coord(x, y);
	return floatCoordToCoord(coord, Map::sizeOfSquare, Map::mapFromX, Map::mapFromY);
}

void enemyLogic(std::list<std::list<Enemy>::iterator>& deleteList)
{
	for (auto i = Enemy::getEnemyList().begin(); i != Enemy::getEnemyList().end(); i++)
	{
		Coord c = floatCoordToCoord((*i).getCoord(), Map::sizeOfSquare, Map::mapFromX, Map::mapFromY);
		if (GameMap::getMap().find(std::pair<int, int>(c.x, c.y))->second.building != nullptr)
		{
			if (GameMap::getMap().find(std::pair<int, int>(c.x, c.y))->second.building->getEnvironmentType() == EnvironmentType::trap)
			{
				dynamic_cast<Trap*>(GameMap::getMap().find(std::pair<int, int>(c.x, c.y))->second.building)->explode(Map::sizeOfSquare, Map::mapFromX, Map::mapFromY);
				delete GameMap::getMap().find(std::pair<int, int>(c.x, c.y))->second.building;
				GameMap::getMap().find(std::pair<int, int>(c.x, c.y))->second.building = nullptr;
			}
		}
		if ((c.x == GameMap::getCastle().getCoord().x && c.y == GameMap::getCastle().getCoord().y) || (*i).getCurHp() <= 0)
		{
			deleteList.push_back(i);
			if ((*i).getCurHp() > 0)
			{
				GameMap::getCastle().getCurHp() -= DAMAGE_BY_ENEMY;
			}
			else
			{
				GameMap::getCastle().getMoney() += (*i).getGold();
			}
			continue;
		}
		FloatCoord fc((*i).getCoord().x, (*i).getCoord().y + Map::sizeOfSquare - 0.001);
		c = floatCoordToCoord(fc, Map::sizeOfSquare, Map::mapFromX, Map::mapFromY);
		if (GameMap::getMap().find(std::pair<int, int>(c.x, c.y))->second.building != nullptr)
		{
			if (GameMap::getMap().find(std::pair<int, int>(c.x, c.y))->second.building->getEnvironmentType() == EnvironmentType::trap)
			{
				dynamic_cast<Trap*>(GameMap::getMap().find(std::pair<int, int>(c.x, c.y))->second.building)->explode(Map::sizeOfSquare, Map::mapFromX, Map::mapFromY);
				delete GameMap::getMap().find(std::pair<int, int>(c.x, c.y))->second.building;
				GameMap::getMap().find(std::pair<int, int>(c.x, c.y))->second.building = nullptr;
			}
		}
		if ((c.x == GameMap::getCastle().getCoord().x && c.y == GameMap::getCastle().getCoord().y) || (*i).getCurHp() <= 0)
		{
			deleteList.push_back(i);
			if ((*i).getCurHp() > 0)
			{
				GameMap::getCastle().getCurHp() -= DAMAGE_BY_ENEMY;
			}
			else
			{
				GameMap::getCastle().getMoney() += (*i).getGold();
			}
			continue;
		}
		fc = FloatCoord((*i).getCoord().x + Map::sizeOfSquare - 0.001, (*i).getCoord().y);
		c = floatCoordToCoord(fc, Map::sizeOfSquare, Map::mapFromX, Map::mapFromY);
		if (GameMap::getMap().find(std::pair<int, int>(c.x, c.y))->second.building != nullptr)
		{
			if (GameMap::getMap().find(std::pair<int, int>(c.x, c.y))->second.building->getEnvironmentType() == EnvironmentType::trap)
			{
				dynamic_cast<Trap*>(GameMap::getMap().find(std::pair<int, int>(c.x, c.y))->second.building)->explode(Map::sizeOfSquare, Map::mapFromX, Map::mapFromY);
				delete GameMap::getMap().find(std::pair<int, int>(c.x, c.y))->second.building;
				GameMap::getMap().find(std::pair<int, int>(c.x, c.y))->second.building = nullptr;
			}
		}
		if ((c.x == GameMap::getCastle().getCoord().x && c.y == GameMap::getCastle().getCoord().y) || (*i).getCurHp() <= 0)
		{
			deleteList.push_back(i);
			if ((*i).getCurHp() > 0)
			{
				GameMap::getCastle().getCurHp() -= DAMAGE_BY_ENEMY;
			}
			else
			{
				GameMap::getCastle().getMoney() += (*i).getGold();
			}
			continue;
		}
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		(*i).move(Map::sizeOfSquare, Map::mapFromX, Map::mapFromY);
		(*i).effectsEnforce(Map::secCounter == 60);
		drawEnemy(*i, Map::sizeOfSquare);
	}
}

void drawCastleHp(Castle& castle)
{
	glLineWidth(16);
	glBegin(GL_LINES);
	glColor4f(0, 0.7f, 0, 1);
	glVertex2f(-16.0f / 9.0f + 9.0f * 0.25f, -1.0f);
	glVertex2f(-16.0f / 9.0f + 1.0f + 9.0f * 0.25f, -1.0f);
	glColor4f(0, 1, 0, 1);
	glVertex2f(-16.0f / 9.0f + 9.0f * 0.25f, -1.0f);
	glVertex2f(-16.0f / 9.0f + 9.0f * 0.25f + 1.0f * (float)castle.getCurHp() / (float)castle.getMaxHp(), -1.0f);
	glEnd();
	glLineWidth(1);
}

void drawInterface()
{
	for (int i = 0; i < 9; i++)
	{
		glColor4f(1, 1, 1, 1.0f/(float)(i + 1));
		float squareSize = 0.25;
		drawSquare(squareSize, -16.0f / 9.0f + 0.25 * i, -1);
	}
	drawCastleHp(GameMap::getCastle());
	for (int i = 0; i < 9; i++)
	{
		glColor4f(0.92f, 1, 0.37f, 1);
		printText(std::to_string(getCost((TowerType)i)), -16.0f / 9.0f + 0.25f * i, -1 + 0.25f, 2.0f);
		glColor4f(0, 0, 0, 1); printText(getStringType((TowerType)i), -16.0f / 9.0f + 0.25f * i, -1 + 0.03f, 1.0f);
	}
}




// GRAPHICS FUNCS

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	WNDCLASSEX wcex;
	HWND hwnd;
	HDC hDC;
	HGLRC hRC;
	MSG msg;
	BOOL bQuit = FALSE;
	float theta = 0.0f;
	int seconds = 0;
	Map::sizeOfSquare = min((Map::mapToX - Map::mapFromX)/ (float)GameMap::getMapSizeX(), (Map::mapToY - Map::mapFromY)/ (float)GameMap::getMapSizeY());
	if (Map::sizeOfSquare != (Map::mapToX - Map::mapFromX) / (float)GameMap::getMapSizeX())
	{
		float a = Map::sizeOfSquare * GameMap::getMapSizeX();
		Map::mapFromX = -(a / 2.0f);
		Map::mapToX = -Map::mapFromX;
	}
	/* register window class */
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_OWNDC;
	wcex.lpfnWndProc = WindowProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = "GLSample";
	wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);;

	//TEST
	//TEST
	
	if (!RegisterClassEx(&wcex))
		return 0;

	/* create main window */
	hwnd = CreateWindowEx(0,
		"GLSample",
		"OpenGL Sample",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		1280,
		720,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(hwnd, nCmdShow);

	/* enable OpenGL for the window */
	EnableOpenGL(hwnd, &hDC, &hRC);
	GameMap::gameInit();
	glGameInit();

	/* program main loop */
	while (!bQuit && GameMap::getCastle().getCurHp() > 0)
	{
		/* check for messages */
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			/* handle or dispatch messages */
			if (msg.message == WM_QUIT)
			{
				bQuit = TRUE;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			/* OpenGL animation code goes here */

			glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			glPushMatrix();
			srand(50);

			drawMap();
			drawInterface();

			std::list<std::list<Enemy>::iterator> deleteList;

			enemyLogic(deleteList);
			
			glColor4f(1, 1, 1, 1); printText(std::to_string(seconds), -16.0f/9.0f, 1, 4.0f);
			glColor4f(0.91f, 1, 0.3f, 1.0f); printText(GameMap::getCastle().getMoneyString(), Map::mapFromX, -0.5, 4.0f);

			glPopMatrix();

			SwapBuffers(hDC);

			for (auto i = Towers::getTowers().begin(); i != Towers::getTowers().end(); i++)
			{
				(*i)->secondEvent(Map::secCounter == 60, Map::sizeOfSquare, Map::mapFromX, Map::mapFromY);
			}

			for (auto i = deleteList.begin(); i != deleteList.end(); i++)
			{
				Enemy::getEnemyList().erase(*i);
			}

			if (Map::secCounter == 60)
			{
				Map::secCounter = 0;
				//ÀŒ√» ¿ «¿¬ﬂ«¿ÕÕ¿ﬂ Õ¿ –¿« ¬ —≈ ”Õƒ”
				seconds++;
				for (auto i = EnemySpawner::getEnemySpawnerList().begin(); i != EnemySpawner::getEnemySpawnerList().end(); i++)
				{
					(*i)->spawnEnemy(Map::sizeOfSquare, Map::mapFromX, Map::mapFromY);
				}
				//ÀŒ√» ¿ «¿¬ﬂ«¿ÕÕ¿ﬂ Õ¿ –¿« ¬ —≈ ”Õƒ”
			}
			/*if (seconds % 100 == 0)
			{
				for (auto i = EnemySpawner::getEnemySpawnerList().begin(); i != EnemySpawner::getEnemySpawnerList().end(); i++)
				{
					(*i)->setSpawnPeriod((*i)->getSpawnPeriod() == 1 ? 1 : (*i)->getSpawnPeriod() - 1);
				}
			}*/
			Map::secCounter++;
			Sleep(1);
		}
	}

	/* shutdown OpenGL */
	DisableOpenGL(hwnd, hDC, hRC);

	/* destroy the window explicitly */
	DestroyWindow(hwnd);

	return msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	float k = (float)Map::w/(float)Map::h;
	float wCoord, hCoord;
	FloatCoord floatCoord(0, 0);
	Coord coord(0, 0);
	switch (uMsg)
	{
	case WM_CLOSE:
		PostQuitMessage(0);
		break;

	case WM_LBUTTONDOWN:
		wCoord = (float)LOWORD(lParam);
		hCoord = -(float)HIWORD(lParam);
		wCoord = (wCoord * 2.0f / (float)Map::w - 1.0f) * k;
		hCoord = (hCoord * (2.0f) / (float)Map::h + 1.0f);
		if ((wCoord > Map::mapFromX && wCoord < Map::mapToX && hCoord > Map::mapFromY && hCoord < Map::mapToY))
		{
			floatCoord = FloatCoord(wCoord, hCoord);
			coord = floatCoordToCoord(floatCoord, Map::sizeOfSquare, Map::mapFromX, Map::mapFromY);
			putBuilding(Map::choicedType, coord.x, coord.y);
		}
		else if ((wCoord < -16.0f / 9.0f + 9 * 0.25f && wCoord > -16.0f / 9.0f && hCoord > -1.0f && hCoord < -1.0f + 0.25f))
		{
			int choice = ((int)((wCoord + 16.0f / 9.0f) / 0.25f));
			Map::choicedType = (TowerType)choice;
		}
		break;
	case WM_RBUTTONDOWN:
		wCoord = (float)LOWORD(lParam);
		hCoord = -(float)HIWORD(lParam);
		wCoord = (wCoord * 2.0f / (float)Map::w - 1.0f) * k;
		hCoord = (hCoord * (2.0f) / (float)Map::h + 1.0f);
		if ((wCoord > Map::mapFromX && wCoord < Map::mapToX && hCoord > Map::mapFromY && hCoord < Map::mapToY))
		{
			floatCoord = FloatCoord(wCoord, hCoord);
			coord = floatCoordToCoord(floatCoord, Map::sizeOfSquare, Map::mapFromX, Map::mapFromY);
			crashBuilding(coord.x, coord.y);
		}
		break;
	case WM_DESTROY:
		return 0;

	case WM_KEYDOWN:
	{
		switch (wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		}
	}
	break;
	case WM_SIZE:
		using Map::h;
		using Map::w;
		w = LOWORD(lParam);
		h = HIWORD(lParam);
		glViewport(0, 0, w, h);
		k = w / (float)h;
		glLoadIdentity();
		glOrtho(-k, k, -1, 1, -1, 1);
		break;

	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}

	return 0;
}

void EnableOpenGL(HWND hwnd, HDC* hDC, HGLRC* hRC)
{
	PIXELFORMATDESCRIPTOR pfd;

	int iFormat;

	/* get the device context (DC) */
	*hDC = GetDC(hwnd);

	/* set the pixel format for the DC */
	ZeroMemory(&pfd, sizeof(pfd));

	pfd.nSize = sizeof(pfd);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW |
		PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 24;
	pfd.cDepthBits = 16;
	pfd.iLayerType = PFD_MAIN_PLANE;

	iFormat = ChoosePixelFormat(*hDC, &pfd);

	SetPixelFormat(*hDC, iFormat, &pfd);

	/* create and enable the render context (RC) */
	*hRC = wglCreateContext(*hDC);

	wglMakeCurrent(*hDC, *hRC);
}

void DisableOpenGL(HWND hwnd, HDC hDC, HGLRC hRC)
{
	wglMakeCurrent(NULL, NULL);
	wglDeleteContext(hRC);
	ReleaseDC(hwnd, hDC);
}

