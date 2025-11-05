#include "Replacer.hpp"
#include <string>

Replacer::Replacer(const std::string &s1, const std::string &s2) : _s1(s1),
	_s2(s2)
{
}

std::string Replacer::replaceIn(const std::string &content) const
{
	if (_s1 == _s2)
		return (content);

	std::string result;
	std::size_t pos = 0;
	std::size_t hit = -1;

	while (true)
	{
		hit = content.find(_s1, pos);
		if (hit == std::string::npos)
		{
			result.append(content, pos, content.size() - pos);
			break ;
		}
		result.append(content, pos, hit - pos);
		result.append(_s2);
		pos = hit + _s1.length();
	}
	return (result);
}