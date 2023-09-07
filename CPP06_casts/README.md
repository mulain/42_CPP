static_cast

Performs implicit type conversions. It is used to convert a value from one type to another type, typically when the types are related by inheritance.
Unlike dynamic_cast, static_cast performs the conversion at compile-time and does not perform any runtime type checking.

reinterpret_cast

Performs a low-level type conversion. It is used to convert a value from one type to another type, regardless of whether the types are related or not. reinterpret_cast simply reinterprets the binary representation of a value as an object of a different type.
Sounds dangerous, is dangerous.
reinterpret_cast can cast between unrelated types, such as a pointer to a class and a pointer to a function, or a pointer to a function and a pointer to a data type. This can lead to undefined behavior.

dynamic_cast

Performs a type-safe (type checking) conversion of objects at runtime.
Typically used for converting a base class pointer (or reference) to a derived class pointer (or reference) when it is necessary to confirm at runtime that the object actually is of the expected derived class type.
If the conversion is not possible (i.e. object is not of expected type), dynamic_cast returns a null pointer or a reference to a nullptr.
Dynamic_cast only works with polymorphic types (classes with virtual functions).
