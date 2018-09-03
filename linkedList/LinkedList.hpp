/**
*	@author
*	@date
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList()
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const
{
	return(m_size);
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
	Node<T>* temp = m_front;

	// immediately return false if the linked list is empty
	if(m_size == 0) return false;
	// loop through list until we get to the end
	while(temp != nullptr){
		// if the value matches, return true
		if(value == temp->getValue()) return true;
		// otherwise go to the next item
		temp = temp->getNext();
	}

	// if we reached the end, value isn't present, return false
	return(false);
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);

}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
	Node<T>* lastNode = nullptr;
	Node<T>* secondintoLast = nullptr;

	// remove failed if the list is empty, return false
	if(m_size == 0) return false;
	if(m_size == 1){
		// delete node
		delete m_front;
		// set front pointer to null and length to 0
		m_front = nullptr;
		m_size = 0;
	}
	else{
		// get pointers to second-from back node and back node
		secondintoLast = m_front->getNext();
		lastNode = secondintoLast->getNext();

		// repeat until we reach last node
		while(lastNode->getNext() != nullptr){
			secondintoLast = secondintoLast->getNext();
			lastNode = lastNode->getNext();
		}

		// delete last node
		delete lastNode;
		// set second-to-last node's next to null and decrement size
		secondintoLast->setNext(nullptr);
		m_size--;
	}

	return true;
}

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
