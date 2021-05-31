#pragma once
#include "Player.h"

template <typename T>
class DynamicArray
{
public:
	DynamicArray(unsigned int size) {
		m_data = new T[size];
		m_allocatedElements = size;
		m_usedElements = 0;
	}
	~DynamicArray() {
		delete[] m_data;
	}

	void AddToArray(const Player& newElement) {
		if (m_allocatedElements == m_usedElements) {
			m_allocatedElements += 1;
			T* newData = new T[m_allocatedElements];
			for (int i = 0; i <= m_usedElements; i++) {
				newData[i] = m_data[i];
			}
			delete m_data;			
		}
		m_data[m_usedElements] = newElement;
		m_usedElements += 1;
	}

	int size() { return m_allocatedElements; }
	int used() { return m_usedElements; }

	T* data() { return m_data; }

protected:
	T* m_data;
	int m_allocatedElements;
	int m_size;
	int m_usedElements;

};

