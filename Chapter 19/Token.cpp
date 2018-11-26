#include "Token.h"

Token & Token::operator=(const std::string &s)
{
	if (tok == STR)
		sval = s;
	else
		new(&sval) std::string(s);
	return *this;
}

Token & Token::operator=(char c)
{
	if(tok==STR) 
		sval.std::string::~string();
	cval = c;
	tok = CHAR;
	return *this;
}

Token & Token::operator=(int i)
{
	if (tok == STR)
		sval.std::string::~string();
	ival = i;
	tok = INT;
	return *this;
}

Token & Token::operator=(double d)
{
	if (tok == STR)
		sval.std::string::~string();
	dval = d;
	tok = DBL;
	return *this;
}

void Token::copyUnion(const Token &t)
{
	switch (t.tok){
	case Token::CHAR: cval = t.cval; break;
	case Token::INT: ival = t.ival; break;
	case Token::DBL: dval = t.dval; break;
	case Token::STR: new(&sval) std::string(t.sval); break;
	}
}

Token & Token::operator=(const Token &t)
{
	if (tok == STR && t.tok != STR)
		sval.std::string::~string();
	if (tok == STR && t.tok == STR)
		sval = t.sval;
	else
		copyUnion(t);
	tok = t.tok;
	return *this;
}

void Token::moveUnion(Token &&t)
{
	switch (t.tok) {
	case Token::CHAR: cval = std::move(t.cval); break;
	case Token::INT: ival = std::move(t.ival); break;
	case Token::DBL: dval = std::move(t.dval); break;
	case Token::STR: new(&sval) std::string(std::move(t.sval)); break;
	}
	tok = std::move(t.tok);
}

Token & Token::operator=(Token &&t)
{
	if (tok == STR && t.tok != STR)
		sval.std::string::~string();
	if (tok == STR && t.tok == STR)
		sval = std::move(t.sval);
	else
		moveUnion(std::move(t));
	tok = std::move(t.tok);
	return *this;
}