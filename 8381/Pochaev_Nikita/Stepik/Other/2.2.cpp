#include <assert.h>
#include <algorithm>
#include <stdexcept>
#include <cstddef>
#include <utility>

namespace stepik
{
  template <class Type>
  struct node
  {
    Type value;
    node* next;
    node* prev;

    node(const Type& value, node<Type>* next, node<Type>* prev)
      : value(value), next(next), prev(prev)
    {
    }
  };

  template <class Type>
  class list; //forward declaration

  template <class Type>
  class list_iterator
  {
  public:
    typedef ptrdiff_t difference_type;
    typedef Type value_type;
    typedef Type* pointer;
    typedef Type& reference;
    typedef size_t size_type;
    typedef std::forward_iterator_tag iterator_category;

    list_iterator()
      : m_node(NULL)
    {
    }

    list_iterator(const list_iterator& other)
      : m_node(other.m_node)
    {
    }

    list_iterator& operator = (const list_iterator& other)
    {
        m_node = other.m_node;
        return *this;
    }

    bool operator == (const list_iterator& other) const
    {
        return m_node == other.m_node;
    }

    bool operator != (const list_iterator& other) const
    {
        return m_node != other.m_node;
    }

    reference operator*()
    {
        return m_node->value;
    }

    pointer operator->()
    {
        return &m_node->value;
    }

    list_iterator& operator++()
    {
        m_node = m_node->next;
        return *this;
    }

    list_iterator operator++(int)
    {
        list_iterator tmp(m_node);
        m_node = m_node->next;
        return tmp;
    }

  private:
    friend class list<Type>;

    list_iterator(node<Type>* p)
      : m_node(p)
    {
    }

    node<Type>* m_node;
  };

  template <class Type>
  class list
  {
  public:
    typedef Type value_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef list_iterator<Type> iterator;

    list()
      : m_head(nullptr), m_tail(nullptr)
    {
    }

    ~list()
    {
      clear();
    }

    list(const list& other)
			: m_head(nullptr), m_tail(nullptr)
    {
        node<Type>* ptr = other.m_head;
        while (ptr) {
            push_back(ptr->value);
            ptr = ptr->next;
        }
    }

    list(list&& other)
        : m_head(other.m_head), m_tail(other.m_tail)
    {
        other.m_head = nullptr;
        other.m_tail = nullptr;
    }

    list& operator= (const list& other)
    {
        clear();
        node<Type>* tmp = other.m_head;
        while (tmp) {
            push_back(tmp->value);
            tmp = tmp->next;
        }

        return *this;
    }

    void push_front(const value_type& value)
    {
      if (empty())
      {
          m_tail = m_head = new node<Type>(value, nullptr, nullptr);
          return;
      }
        
      m_head = new node<Type>(value, m_head, nullptr);
	  m_head->next->prev = m_head;
    }

    void pop_front()
    {
      if (m_head == m_tail)
      {
          delete m_head;
          m_head = m_tail = nullptr;
          return;
      }
      
      m_head = m_head->next;
      delete m_head->prev;
      m_head->prev = nullptr;
    }

    void pop_back()
    {
      if (m_head == m_tail)
      {
          delete m_head;
          m_head = m_tail = nullptr;
          return;
      }
      
      m_tail = m_tail->prev;
      delete m_tail->next;
      m_tail->next = nullptr;
    }

    void clear()
    {
      while (!empty())
				pop_back();
    }

    bool empty() const
    {
      return m_head == nullptr;
    }

    size_t size() const
    {
      size_t count = 0;
        node<Type>* tmp = m_head;
        while (tmp != nullptr)
        {
            count++;
            tmp = tmp->next;
        }

        return count;
    }

    list::iterator begin()
    {
      return iterator(m_head);
    }

    list::iterator end()
    {
      return iterator();
    }

    void push_back(const value_type& value)
    {
        if (empty()) {
            m_tail = m_head = new node<Type>(value, nullptr, nullptr);
            return;
        }
        m_tail->next = new node<Type>(value, nullptr, m_tail);
        m_tail = m_tail->next;
    }

    reference front()
    {
        return m_head->value;
    }

    reference back()
    {
        return m_tail->value;
    }

    iterator insert(iterator pos, const Type& value)
    {
        if (pos.m_node == nullptr) {
            push_back(value);
            return iterator(m_tail);
        }

        if (pos.m_node->prev == nullptr) {
            push_front(value);
            return iterator(m_head);
        }

        node<Type>* tmp = pos.m_node->prev;
        pos.m_node->prev = new node<Type>(value, pos.m_node, tmp);
        tmp->next = pos.m_node->prev;

        return iterator(pos.m_node->prev);
    }

    iterator erase(iterator pos)
    {
        if (pos.m_node->next == nullptr) {
            pop_back();
            return iterator();
        }

        if (pos.m_node->prev == nullptr) {
            pop_front();
            return iterator(m_head);
        }

        node<Type>* tmp = pos.m_node;
        delete pos.m_node;
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;

        return tmp->next;
    }

  private:
    //your private functions

    node<Type>* m_head;
    node<Type>* m_tail;
  };

}// namespace stepik