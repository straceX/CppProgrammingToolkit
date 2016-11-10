
bool is_rotate(const std::string &s1, const std::string &s2)
{
	if(s1.empty() || s2.empty())	return false;

	return s1.size() == s2.size() && std::equal(s1.begin(), s1.end(), s2.rbegin());		
}

size_t count_character(const std::string &sparam,char ch)
{	 
	if(sparam.empty())	return;

	return std::count(sparam.begin(), sparam.end(), ch);
}

size_t count_words(const std::string &sparam, const std::string &sword)
{
	 if(sparam.empty() || sword.empty())	return;

	size_t iter = 0;
	size_t ival = 0;
	
	while ((iter = sparam.find(sword, ++iter)) != std::string::npos)
		++ival;
	return ival;
}
size_t replace_all_words(std::string& sparam, const std::string& from, const std::string& to) 
{
		
	if(sparam.empty() || from.empty() || to.empty())	return 0;
	
	size_t start_pos = 0;
	int ival = 0;
	while ((start_pos = str.find(from,start_pos)) != std::string::npos)
	{
		str.replace(start_pos, from.length(), to);
		std::cout << str << std::endl;
		++start_pos;
		++ival;
	}
	
	return ival;
}

bool is_string_character_unique(const std::string &sparam)
{
	if (sparam.length() > 256)
		return false;

	std::bitset<256> bset;

	for (unsigned char c : sparam) {
		if (bset.test(c))
			return false;
		
		bset.set(c);
	}
	return true;
}