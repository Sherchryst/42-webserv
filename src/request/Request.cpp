/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 19:51:17 by sgah              #+#    #+#             */
/*   Updated: 2021/12/01 19:49:19 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Request.hpp"

Request::Request(void): _method (""), _version(""), _ret(200), _body(""), _port(8080), _path(""), _query("") {}

Request::Request(Request const & src)
{
	*this = src;
}

Request::~Request(void) {}

Request&	Request::operator=(const Request &rhs)
{
	if (this != &rhs)
	{
		_method = rhs._method;
		_version = rhs._version;
		_ret = rhs._ret;
		_body = rhs._body;
		_port = rhs._port;
		_path = rhs._path;
		_query = rhs._query;
		_headers = rhs._headers;
		_env_for_cgi = rhs._env_for_cgi;
		_lang = rhs._lang;
	}
	return (*this);
}

void				Request::resetDirective(void)
{
	_headers.clear();

	_headers["Accept-Charsets"] = "";
	_headers["Accept-Language"] = "";
	_headers["Allow"] = "";
	_headers["Auth-Scheme"] = "";
	_headers["Authorization"] = "";
	_headers["Content-Language"] = "";
	_headers["Content-Length"] = "";
	_headers["Content-Location"] = "";
	_headers["Content-Type"] = "";
	_headers["Date"] = "";
	_headers["Host"] = "";
	_headers["Last-Modified"] = "";
	_headers["Location"] = "";
	_headers["Referer"] = "";
	_headers["Retry-After"] = "";
	_headers["Server"] = "";
	_headers["Transfer-Encoding"] = "";
	_headers["User-Agent"] = "";
	_headers["Cookie"] = "";
	_headers["Www-Authenticate"] = "";
	_headers["Connection"] = "Keep-Alive";
}

void										Request::setRet(int ret)
{
	_ret = ret;
}

void										Request::setMethod(std::string method)
{
	_method = method;
}

void										Request::setPath(std::string path)
{
	_path = path;
}

void										Request::setVersion(std::string version)
{
	_version = version;
}

void										Request::setHeader(std::string token, std::string value)
{
	_headers[token] = value;
}

int											Request::getPort(void) const
{
	return _port;
}

const std::list<std::pair<std::string, float> >&	Request::getLang() const
{
	return _lang;
}

const std::map<std::string, std::string>&	Request::getEnv() const
{
	return _env_for_cgi;
}

std::string		Request::getMethod(void) const
{
	return (_method);
}

std::string			Request::getPath() const
{
	return _path;
}

std::string		Request::getBody(void) const
{
	return _body;
}

const std::string&			Request::getQuery() const
{
	return _query;
}

int					Request::getRet() const
{
	return _ret;
}

std::string		Request::getVersion(void) const
{
	return (_version);
}

std::map<std::string, std::string>	Request::getHeaders(void) const
{
	return (_headers);
}

std::string		Request::getHeader(std::string str)
{
	return (_headers[str]);
}
