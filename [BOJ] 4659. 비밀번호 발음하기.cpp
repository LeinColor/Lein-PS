#include <iostream>
#include <string>
using namespace std;


bool is_vowel(char c)
{
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return true;
	return false;
}

bool is_contain_vowel(const string& s)
{
	for (size_t i = 0; i < s.length(); i++) {
		if (is_vowel(s[i]))
			return true;
	}
	return false;
}

bool is_triple(const string& s)
{
	int count = 0;

	bool prev_type = is_vowel(s[0]);
	bool curr_type = is_vowel(s[0]);
	for (size_t i = 0; i < s.length(); i++) {
		curr_type = is_vowel(s[i]);

		if (prev_type == curr_type)
			count++;
		else
			count = 1;

		prev_type = curr_type;

		if (count == 3)
			return true;
	}
	return false;
}

bool is_repeated(const string& s)
{
	int count = 0;

	char prev_char = s[0];
	char curr_char = s[0];
	for (size_t i = 0; i < s.length(); i++) {
		curr_char = s[i];

		if (prev_char == curr_char)
			count++;
		else
			count = 1;

		prev_char = curr_char;

		if (count == 2 && (curr_char != 'e' && curr_char != 'o'))
			return true;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (true) {
		string s;
		cin >> s;

		if (s == "end")
			return 0;

		if (is_contain_vowel(s) && !is_triple(s) && !is_repeated(s))
			cout << "<" << s << "> is acceptable.\n";
		else
			cout << "<" << s << "> is not acceptable.\n";
	}

	return 0;
}