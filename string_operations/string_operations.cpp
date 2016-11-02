
bool is_rotate(const std::string &s1, const std::string &s2)
{
	return s1.size() == s2.size() && std::equal(s1.begin(), s1.end(), s2.rbegin());		
}

size_t count_character(const std::string &sparam,char ch)
{
	return std::count(sparam.begin(), sparam.end(), ch);
}

size_t count_words(const std::string &sparam, const std::string &sword)
{
	size_t iter = 0;
	size_t ival = 0;
	while ((iter = sparam.find(sword, ++iter)) != std::string::npos)
		++ival;
	return ival;
}
