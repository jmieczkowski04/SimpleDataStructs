#pragma once

namespace zasty
{
	template <typename T> struct TQueueElement
	{
	public:
		T element;
		TQueueElement<T>* prev;
	};

	template <typename T> class TQueue
	{
	private:
		TQueueElement<T> * first;
		TQueueElement<T> * last;
	public:
		TQueue();
		bool IsEmpty();
		void Enqueue(T element);
		T Dequeue();
	};

	template <typename T> TQueue<T>::TQueue()
	{
		first = nullptr;
		last = nullptr;
	}

	template <typename T> bool TQueue<T>::IsEmpty()
	{
		return first != nullptr;
	}

	template <typename T> void TQueue<T>::Enqueue(T element)
	{
		TQueueElement<T> * newElement = new TQueueElement<T>();
		newElement->element = element;
		newElement->prev = nullptr;

		if (last != nullptr)
		{
			last->prev = newElement;
		}

		last = newElement;

		if (first == nullptr)
			first = newElement;

	}

	template <typename T> T TQueue<T>::Dequeue()
	{
		if (first == nullptr)
			return (T)nullptr;

		TQueueElement<T>* elementToDequeue = first;
		first = elementToDequeue->prev;

		if (first == nullptr)
			last = nullptr;

		T value = elementToDequeue->element;
		delete elementToDequeue;
		return value;
	}
}