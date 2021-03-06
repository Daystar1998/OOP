// Definition by Dr. Steil and Dr. Foust
// Implementation by Matthew Day

#include <vector>
#include <stdexcept>

namespace util {
	template <typename KeyType, typename ValueType>
	class Map {

	public:

		// Author: Matthew Day
		class IVisitor {

		public:

			virtual ~IVisitor() {}

			virtual void visit(KeyType &key, ValueType &value) = 0;
		};

		// Wrapper is an inner class of the Map Template
		class Wrapper {
		public:
			//this is a type cast operator that can be used to cast an object
			//of type Wrapper to an object of type ValueType
			operator ValueType&();
			ValueType* operator &();
			const ValueType& operator =(const ValueType& rValue);

		private:
			Wrapper(Map &map, const KeyType &key);
			Wrapper(const Wrapper & value);
			Map& map;
			KeyType key;
			ValueType* value;

			friend class Map;
		};

		Wrapper operator[](const KeyType& key);
		unsigned size();

		// Author: Matthew Day
		class Iterator {

		private:

			Map<KeyType, ValueType> &map;
			size_t index;

			Iterator(Map<KeyType, ValueType> &map);

			friend class Map;
		public:

			Iterator& operator++();

			Iterator operator++(int);

			Iterator& operator--();

			Iterator operator--(int);

			ValueType& operator*();

			// Added because the compiler throws an error stating the copy assignment operator was deleted
			const Iterator& operator=(const Iterator &other);
		};

		Map<KeyType, ValueType>::Iterator getIterator(KeyType &key);

		void visit(IVisitor &visitor);

		Iterator begin();

		Iterator end();
	private:
		std::vector<KeyType> keys;
		std::vector<ValueType> values;

		ValueType* find(const KeyType &key);
		ValueType* set(const KeyType &key, const ValueType &value);
	};

	/*==========================================================================
	 * Map class methods
	 */

	template <typename KeyType, typename ValueType>
	typename Map<KeyType, ValueType>::Wrapper Map<KeyType, ValueType>::operator[](const KeyType& key) {
	   //return a Wrapper object that has a reference to this Map and the key that was passed in

		return Wrapper(*this, key);
	}

	template <typename KeyType, typename ValueType>
	unsigned Map<KeyType, ValueType>::size() {
		//return the number of items that are in the keys or values list
		return (unsigned)keys.size();
	}

	template <typename KeyType, typename ValueType>
	ValueType* Map<KeyType, ValueType>::find(const KeyType &key) {

		ValueType *result = nullptr;

			//loop through the keys list to see if the key parameter is in the list
		for (unsigned int i = 0; i < keys.size(); i++) {

			//if the key is in the list, return the address of the value at that same
			//index in the values list
			if (keys[i] == key) {

				result = &values[i];
				break;
			}
		}

			//if the key is NOT in the list, return NULL

		return result;
	}

	template <typename KeyType, typename ValueType>
	ValueType* Map<KeyType, ValueType>::set(const KeyType &key, const ValueType &value) {

		ValueType *result = nullptr;

		for (unsigned int i = 0; i < keys.size(); i++) {

			  //if the key is already in the keys list,
			  //change the value corresponding to that key value passed to this method
			if (keys[i] == key) {

				values[i] = value;
				result = &values[i];

				break;
			}
		}

			  //if the key is NOT in the list, add it and the value to the end of their lists
		if (result == nullptr) {

			keys.push_back(key);
			values.push_back(value);

			result = &values[values.size() - 1];
		}

			  // return the address of the value, in the values list, that was changed or added

		return result;
	}

	template <typename KeyType, typename ValueType>
	typename Map<KeyType, ValueType>::Iterator Map<KeyType, ValueType>::begin() {

		Iterator result(*this);

		result.index = 0;

		return result;
	}

	template <typename KeyType, typename ValueType>
	typename Map<KeyType, ValueType>::Iterator Map<KeyType, ValueType>::end() {

		Iterator result(*this);

		result.index = this->size() - 1;

		return result;
	}

 /*==========================================================================
  * Wrapper methods
  */

	template <typename KeyType, typename ValueType>
	Map<KeyType, ValueType>::Wrapper::Wrapper(Map &map, const KeyType &key)
		: map(map), key(key) {
			  //in the member initialization list - set the map and the key members to
			  //the values passed to the constructor

			  //in the body of the constructor - set the value member to the
			  //map's value with that key. Hint: use map.find

		value = map.find(key);
	}

	//Copy construxtor
	template <typename KeyType, typename ValueType>
	Map<KeyType, ValueType>::Wrapper::Wrapper(const Wrapper& rValue)
		: map(rValue.map), key(rValue.key), value(rValue.value) {
			  //in the member initialization list - set the map, the key, and the value
			  //members to the values passed to the constructor
	}

	//conversion operator, from a Wrapper to a ValueType
	template <typename KeyType, typename ValueType>
	Map<KeyType, ValueType>::Wrapper::operator ValueType&() {
			  //if the value is null throw an std::range_error exception
			  //with the text "Key not found in map"
			  //stdexcept is included for this purpose
		if (value == nullptr) {

			throw std::range_error("Key not found in map");
		}

			  //if the value is not null return the value (dereferenced)
		return *value;
	}

	//address of operator. This is used when the programmer tries to 
	//find the address of a Wrapper object.  We return the address of the
	//value inside the wrapper instead.
	template <typename KeyType, typename ValueType>
	ValueType* Map<KeyType, ValueType>::Wrapper::operator &() {
			  //if the value is null throw an std::range_error exception
			  //with the text "Key not found in map"
			  //stdexcept is included for this purpose
		if (value == nullptr) {

			throw std::range_error("Key not found in map");
		}

			  //if the value is not null return the value pointer
		return value;
	}

	//assignment operator.  This is used when a wrapper is the l-value in an assignment 
	//and the r-value is of type ValueType
	template <typename KeyType, typename ValueType>
	const ValueType& Map<KeyType, ValueType>::Wrapper::operator =(const ValueType& rValue) {
			  // if the value member is null
			  // set the map's value for the current key to the value parameter (use map.set)
			  // set the value member of the wrapper to the rValue (you can use the value returned from map.set)
		if (value == nullptr) {

			value = map.set(key, rValue);

			  //if the value member is NOT null
			  //set the member value to the value parameter
			  //(you will need to dereference the member value to make this assignment)
		} else {

			*value = rValue;
		}

			  //return the rValue parameter

		return rValue;
	}

	template <typename KeyType, typename ValueType>
	typename Map<KeyType, ValueType>::Iterator Map<KeyType, ValueType>::getIterator(KeyType &key) {

		Iterator result(*this);

		bool foundKey = false;

		for (size_t i = 0; i < keys.size(); i++) {

			if (keys[i] == key) {

				foundKey = true;
				result.index = i;

				break;
			}
		}

		if (!foundKey) {

			throw std::range_error("Key not found in map");
		}

		return result;
	}

	template <typename KeyType, typename ValueType>
	void Map<KeyType, ValueType>::visit(Map<KeyType, ValueType>::IVisitor &visitor) {

		for (size_t i = 0; i < keys.size(); i++) {

			visitor.visit(keys[i], values[i]);
		}
	}

	template <typename KeyType, typename ValueType>
	Map<KeyType, ValueType>::Iterator::Iterator(Map<KeyType, ValueType> &map)
		:map(map) {}

	template <typename KeyType, typename ValueType>
	typename Map<KeyType, ValueType>::Iterator& Map<KeyType, ValueType>::Iterator::operator++() {

		this->index++;

		if (this->index >= this->map.size()) {

			this->index = 0;
		}

		return *this;
	}

	template <typename KeyType, typename ValueType>
	typename Map<KeyType, ValueType>::Iterator Map<KeyType, ValueType>::Iterator::operator++(int) {

		Iterator result = *this;

		this->index++;

		if (this->index >= this->map.size()) {

			this->index = 0;
		}

		return result;
	}

	template <typename KeyType, typename ValueType>
	typename Map<KeyType, ValueType>::Iterator& Map<KeyType, ValueType>::Iterator::operator--() {

		if (this->index == 0) {

			this->index = this->map.size() - 1;
		} else {

			this->index--;
		}

		return *this;
	}

	template <typename KeyType, typename ValueType>
	typename Map<KeyType, ValueType>::Iterator Map<KeyType, ValueType>::Iterator::operator--(int) {

		Iterator result = *this;

		if (this->index == 0) {

			this->index = this->map.size() - 1;
		} else {

			this->index--;
		}

		return result;
	}

	template <typename KeyType, typename ValueType>
	ValueType& Map<KeyType, ValueType>::Iterator::operator*() {

		return this->map.values[this->index];
	}

	template <typename KeyType, typename ValueType>
	const typename Map<KeyType, ValueType>::Iterator& Map<KeyType, ValueType>::Iterator::operator=(const Map<KeyType, ValueType>::Iterator &other) {

		this->map = other.map;
		this->index = other.index;

		return *this;
	}
}