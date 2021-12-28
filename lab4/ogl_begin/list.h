#pragma once

#pragma once

#include <iostream>
#include <iterator>
namespace std {
	template <class T>
	struct Node
	{
		T data;
		Node<T>* next;
		Node<T>* prev;
		Node(T data = T(), Node* next = nullptr, Node* prev = nullptr) : data(data), next(next), prev(prev) {};
		~Node() {}
	};

	template <class T>
	class list
	{
	private:
		Node<T>* head = nullptr;
		Node<T>* last = nullptr;
		size_t size = 0;
	public:
		class iterator
		{
		public:
			Node<T>* cur;
			inline iterator(Node<T>* first) : cur(first) {}

			inline iterator& operator++ (int)
			{
				cur = cur->next;
				return *this;
			}

			inline iterator& operator-- (int)
			{
				cur = cur->prev;
				return *this;
			}

			inline Node<T>*& operator->()
			{
				return cur;
			}
			inline T& operator*()
			{
				return cur->data;
			}

			inline friend bool operator == (iterator it, iterator oth)
			{
				return (oth).cur == (it).cur;
			}

			inline friend bool operator != (iterator it, iterator oth)
			{
				return (it).cur != (oth).cur;
			}
		};

		size_t getSize() const { return size; }

		list() : head(nullptr), last(nullptr), size(0)
		{

		}

		~list()
		{
			clear();
		}

		void erase(iterator _where)
		{
			if (_where == begin())
			{
				pop_front();
				return;
			}
			if (_where.cur->next == nullptr)
			{
				_where.cur->prev->next = nullptr;
				last = _where.cur->prev;
				delete _where->cur;
				size--;
				return;
			}
			_where.cur->prev->next = _where.cur->next;
			_where.cur->next->prev = _where.cur->prev;
			delete _where->cur;
			size--;
		}

		void push_back(T data)
		{
			switch (size)
			{
			case 0:
				head = last = new Node<T>(data, nullptr, nullptr);
				size++;
				break;
			default:
				last->next = new Node<T>(data, nullptr, last);
				size++;
				last = last->next;
				break;
			}
		}

		void push_front(T data)
		{
			switch (size)
			{
			case 0:
				head = last = new Node<T>(data, nullptr, nullptr);
				size++;
				break;
			default:
				head->prev = new Node<T>(data, head, nullptr);
				size++;
				head = head->prev;
				break;
			}
		}

		T& front() { return head; }

		T& back() { return last; }

		void insert(iterator i, T data)
		{
			if (i == end())
			{
				push_back(data);
				return;
			}
			else if (i == begin())
			{
				push_front(data);
				return;
			}
			i.cur->prev = new Node<T>(data, i.cur, i.cur->prev);
			Node<T>* node = i.cur->prev->prev;
			node->next = i.cur->prev;
			size++;
		}

		void pop_front()
		{
			switch (size)
			{
			case 0:
				break;
			case 1:
				delete head;
				head = last = nullptr;
				size--;
				break;
			default:
				Node<T>* node = head->next;
				delete head;
				node->prev = nullptr;
				head = node;
				size--;
				break;
			}
		}

		void pop_back()
		{
			switch (size)
			{
			case 0:
				break;
			case 1:
				delete head;
				head = last = nullptr;
				size--;
				break;
			default:
				Node<T>* node = last->prev;
				delete last;
				node->next = nullptr;
				last = node;
				size--;
				break;
			}
		}

		void clear()
		{
			for (auto i = begin(); i != end();)
			{
				auto b = i;
				i++;
				delete (b).cur;
			}
			size = 0;
		}

		iterator begin()
		{
			return Iterator(head);
		}

		iterator end()
		{
			return iterator(nullptr);
		}

	};
}