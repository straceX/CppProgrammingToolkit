
bool is_rotate(const std::string &s1, const std::string &s2)
{
	return s1.size() == s2.size() && std::equal(s1.begin(), s1.end(), s2.rbegin());		
}