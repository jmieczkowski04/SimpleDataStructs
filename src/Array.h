#pragma once

#include <cassert>


namespace zasty
{
	template <typename T>
	class TArray
	{
	public:
		TArray();
		~TArray();
		T& operator[](size_t i);
		size_t Num();
		void Append(T element);
		void Remove(size_t i);
		void Reserve(size_t N);
		void SetAutoAllocation(bool AutoAlloc);
	private:
		T* data;
		size_t size;
		size_t realSize;
		bool autoAlloc = true;
	};

	template <typename T> TArray<T>::TArray()
	{
		size = 0;
		realSize = 0;
		data = new T[0];
	}

	template <typename T> TArray<T>::~TArray()
	{
		delete data;
	}

	template <typename T> T& TArray<T>::operator[](size_t i)
	{
		assert(size > i);
		return data[i];
	}

	template <typename T> size_t TArray<T>::Num()
	{
		return size;
	}

	template <typename T> void TArray<T>::Append(T element)
	{
		assert(!((!autoAlloc) && (realSize == size)));

		size++;
		if (realSize < size)
		{
			T* data2 = data;
			data = new T[size];
			realSize++;
			memcpy(data, data2, sizeof(T) * (size - 1));
			delete data2;
		}
		data[size - 1] = element;
	}

	template <typename T> void TArray<T>::Remove(size_t i)
	{
		if (i >= size)
			return;

		if (i != (size - 1))
			memcpy(data + i, data + i + 1, sizeof(T) * (size - (i + 1)));

		size--;

		if (autoAlloc)		//should align dealloc memory?
		{
			T* data2 = data;
			data = new T[size];
			realSize = size;
			memcpy(data, data2, sizeof(T) * size);
			delete data2;
		}
	}

	template <typename T> void TArray<T>::Reserve(size_t N)
	{
		if (N == realSize)	//the same size
			return;

		T* data2 = data;
		data = new T[N];
		realSize = N;

		if (N < size)		// shrink
			size = N;

		memcpy(data, data2, sizeof(T) * size);
		delete data2;
	}

	template <typename T> void TArray<T>::SetAutoAllocation(bool AutoAlloc)
	{
		autoAlloc = AutoAlloc;
	}
}

