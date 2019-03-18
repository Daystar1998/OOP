// Definition by Dr. Steil and Dr. Foust

#include <vector>
#include <stdexcept>

namespace util {
	template <typename KeyType, typename ValueType>
	class Map {

	public:
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
	}

	template <typename KeyType, typename ValueType>
	unsigned Map<KeyType, ValueType>::size() {
		//return the number of items that are in the keys or values list
	}

	template <typename KeyType, typename ValueType>
	ValueType* Map<KeyType, ValueType>::find(const KeyType &key) {
			//loop through the keys list to see if the key parameter is in the list

			//if the key is in the list, return the address of the value at that same
			//index in the values list

			//if the key is NOT in the list, return NULL
	}

	template <typename KeyType, typename ValueType>
	ValueType* Map<KeyType, ValueType>::set(const KeyType &key, const ValueType &value) {
			  //if the key is already in the keys list,
			  //change the value corresponding to that key value passed to this method

			  //if the key is NOT in the list, add it and the value to the end of their lists

			  // return the address of the value, in the values list, that was changed or added
	}

 /*==========================================================================
  * Wrapper methods
  */

	template <typename KeyType, typename ValueType>
	Map<KeyType, ValueType>::Wrapper::Wrapper(Map &map, const KeyType &key) {
			  //in the member initialization list - set the map and the key members to
			  //the values passed to the constructor

			  //in the body of the constructor - set the value member to the
			  //map's value with that key. Hint: use map.find
	}

	//Copy construxtor
	template <typename KeyType, typename ValueType>
	Map<KeyType, ValueType>::Wrapper::Wrapper(const Wrapper& rValue) {
			  //in the member initialization list - set the map, the key, and the value
			  //members to the values passed to the constructor
	}

	//conversion operator, from a Wrapper to a ValueType
	template <typename KeyType, typename ValueType>
	Map<KeyType, ValueType>::Wrapper::operator ValueType&() {
			  //if the value is null throw an std::range_error exception
			  //with the text "Key not found in map"
			  //stdexcept is included for this purpose

			  //if the value is not null return the value (dereferenced)
	}

	//address of operator. This is used when the programmer tries to 
	//find the address of a Wrapper object.  We return the address of the
	//value inside the wrapper instead.
	template <typename KeyType, typename ValueType>
	ValueType* Map<KeyType, ValueType>::Wrapper::operator &() {
			  //if the value is null throw an std::range_error exception
			  //with the text "Key not found in map"
			  //stdexcept is included for this purpose

			  //if the value is not null return the value pointer
	}

	//assignment operator.  This is used when a wrapper is the l-value in an assignment 
	//and the r-value is of type ValueType
	template <typename KeyType, typename ValueType>
	const ValueType& Map<KeyType, ValueType>::Wrapper::operator =(const ValueType& rValue) {
			  // if the value member is null
			  // set the map's value for the current key to the value parameter (use map.set)
			  // set the value member of the wrapper to the rValue (you can use the value returned from map.set)


			  //if the value member is NOT null
			  //set the member value to the value parameter
			  //(you will need to dereference the member value to make this assignment)

			  //return the rValue parameter
	}
}