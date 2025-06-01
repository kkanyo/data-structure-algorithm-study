#include "LinkedQueue.h"

template<typename T>
LinkedQueue<T>::LinkedQueue()
{
	this->Front = nullptr;
	this->Rear = nullptr;
	this->Count = 0;
}

template<typename T>
void LinkedQueue<T>::Enqueue( T data )
{
	Node* newNode = ( Node* ) malloc( sizeof( Node ) );
	if ( newNode == nullptr )
	{
		fprintf( stderr, "[line %d][%s] newNode is nullptr, ", __LINE__, __FUNCTION__ );
		return;
	}

	newNode->Data = data;
	newNode->Next = nullptr;

	if ( this->IsEmpty() )
	{
		this->Front = newNode;
		this->Rear = newNode;
	}
	else
	{
		this->Rear->Next = newNode;
		this->Rear = newNode;
	}

	this->Count++;
}

template<typename T>
T LinkedQueue<T>::Dequeue()
{
	if ( this->IsEmpty() )
	{
		fprintf( stderr, "[line %d][%s] queue is empty, ", __LINE__, __FUNCTION__ );
		return T();
	}

	Node* current = this->Front;
	if ( this->Front->Next == nullptr )
	{
		this->Front = nullptr;
		this->Rear = nullptr;
	}
	else
	{
		this->Front = this->Front->Next;
	}

	this->Count--;

	return current->Data;
}

template<typename T>
int LinkedQueue<T>::GetSize()
{
	return this->Count;
}

template<typename T>
bool LinkedQueue<T>::IsEmpty()
{
	return this->Front == nullptr;
}
