#pragma once
uint64_t GetProcessBase(int pid);
uint64_t GetProcessId(const char* process_name);
uint64_t GetProcessId();

bool read_raw(int pid, uint64_t address, void* buffer, size_t size);
bool write_raw(int pid, uint64_t address, void* buffer, size_t size);

template<typename T>
inline bool read(uint64_t address, T& value) {
	return read_raw(GetProcessId(), address, &value, sizeof(T));
}

template<typename T>
inline bool write(uint64_t address, const T& value) {
	return write_raw(GetProcessId(), address, (void*)&value, sizeof(T));
}
template<typename T>
inline bool read_array(uint64_t address, T* array, size_t len) {
	return read_raw(GetProcessId(), address, array, sizeof(T) * len);
}

template<typename T>
inline T read(uint64_t address) {
	T buffer{ };
	read(address, buffer);
	return buffer;
}

inline std::string read_string(uintptr_t addr, int max_length = 1000) {
	std::string str = "";
	std::vector<char> chars(max_length);
	read_raw(GetProcessId(), addr, chars.data(), max_length);

	// Loop through all the characters untill we find a null byte indicating the end of a string
	for (size_t i = 0; i < chars.size(); i++) {
		if (chars[i] == '\0') break;
		str.push_back(chars[i]);
	}

	// Prevent strings with only a null byte in it
	if ((int)str[0] == 0 && str.size() == 1) return "";
	return str;
}