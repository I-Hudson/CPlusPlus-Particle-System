#pragma once
#ifndef __MANAGER_H__
#define __MANAGER_H__


template<typename T>
class Manager
{
protected:
	Manager();
	virtual ~Manager();

private:
	//A private poniter to an instance of this calss
	static T* m_pInstance;
public:
	static T* CreateInstance();
	static T* GetInstance();
	static void DestoryInstance();

};

template<typename T> T* Manager<T>::CreateInstance()
{
	if (m_pInstance == nullptr)
	{
		m_pInstance = new T();
	}
	return m_pInstance;
}

template<typename T> T* Manager<T>::GetInstance()
{
	return m_pInstance;
}

template<typename T> void Manager<T>::DestoryInstance()
{
	if(m_pInstance != nullptr)
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

template<typename T>T* Manager<T>::m_pInstance = nullptr;

template<typename T> Manager<T>::Manager() {}

template<typename T> Manager<T>::~Manager() {}

#endif // __MANAGER_H__