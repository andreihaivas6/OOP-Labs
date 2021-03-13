#pragma once
#include <iostream>

template <class K, class V>
class Map
{
private:
	struct data
	{
		K key;
		V value;
		int index;
	};
	data map[100];
	int count;

public:
	Map() : count(0) {}
	const data* begin() {
		return &map[0];
	}
	const data* end() {
		return &map[count];
	}

	V & operator[](K);
	int keyPosition(K); // -1 daca nu exista in map

	void Set(K, V);
	bool Get(const K&, V&);
	int Count() const;
	void Clear();
	bool Delete(const K&);
	bool Includes(const Map<K, V>& map_); // ca sa pot folosi functiile pt o variabila de tipul const (map_), 
										  // functiile trebuie sa aiba la final const 
										  // int Count() const -> sa stie ca nu se modifica nimic in functie
};

template <class K, class V>
V & Map <K, V>::operator[](K key_)
{
	if (keyPosition(key_) == -1){
		map[count].key = key_;
		map[count].index = count;
		count++;
		return map[keyPosition(key_)].value;
	}
	else 
		return map[keyPosition(key_)].value;
}

template <class K, class V>
int Map <K, V>::keyPosition(K key)
{
	for (int i = 0; i < this->count; i++)
		if (this->map[i].key == key)
			return i;
	return -1;
}

template <class K, class V>
void Map <K, V>::Set(K key, V value)
{
	if (keyPosition(key) != -1)
		this->map[keyPosition(key)].value = value;
	else
		std::cout << "Nu exista acest key in map \n"; 
}

template <class K, class V>
bool Map <K, V>::Get(const K& key, V& value)
{
	if (keyPosition(key) != -1) {
		value = this->map[keyPosition(key)].value;
		return true;
	}
	return false;
}

template <class K, class V>
int Map <K, V>::Count() const
{
	return this->count;
}

template <class K, class V>
void Map <K, V>::Clear()
{
	this->count = 0;
}

template <class K, class V>
bool Map <K, V>::Delete(const K& key)
{
	if (keyPosition(key) != -1)
	{
		for (int i = keyPosition(key); i < this->count - 1; ++i) {
			this->map[i].key = this->map[i + 1].key;
			this->map[i].value = this->map[i + 1].value;
		}
		this->count--;
		return true;
	}
	return false;
}

template <class K, class V>
bool Map <K, V>::Includes(const Map <K, V>& map_)
{
	for (int i = 0; i < map_.Count(); i++)
		if (this->keyPosition(map_.map[i].key) == -1)
			return false;
	return true;
}
