/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 19:51:17 by sgah              #+#    #+#             */
/*   Updated: 2022/01/17 20:56:48 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Request.hpp"

Request::Request(void): raw_request(""), header_ready(false), body_ready(false), contentSize(0), bodySize(0), _method (""), _version(""), _ret(200), _body(""), _port(8080), _path(""), _query("")  {}

Request::Request(Request const & src)
{
	*this = src;
}

Request::~Request(void) {}

Request&	Request::operator=(const Request &rhs)
{
	contentSize = rhs.contentSize;
	bodySize = rhs.bodySize;
	_method = rhs._method;
	_version = rhs._version;
	_ret = rhs._ret;
	_body = rhs._body;
	_port = rhs._port;
	_path = rhs._path;
	_query = rhs._query;
	_headers = rhs._headers;
	_env_for_cgi = rhs._env_for_cgi;
	_network = rhs._network;
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const Request &r)
{
	out << "Method: " << r._method << std::endl;
	out << "Version: " << r._version << std::endl;
	out << "Body: " << r._body << std::endl;
	out << "Path: " << r._path << std::endl;
	for (stringMap::const_iterator i = r._headers.begin(); i != r._headers.end(); i++)
		out << i->first + ": " + i->second << std::endl;
	return (out);
}

void				Request::resetDirective(void)
{
	_version = "";
	_method = "";
	_ret = 200;
	_body = "";
	_port = 8080;
	_path = "";
	_query = "";
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

void										Request::resetRequest(void)
{
	header_ready = false;
	body_ready = false;
	bodySize = 0;
	contentSize = 0;
	raw_request.clear();
	header.clear();
	_network.hostName.clear();
	_network.host.s_addr = inet_addr("0");
	_network.port = 0;
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
	size_t start;

	if ((start = path.find_first_of("?")) == std::string::npos)
		_path = path;
	else
		_path = path.substr(0, start);
	_query = path.substr(start + 1);
}

void										Request::setVersion(std::string version)
{
	_version = version;
}

void										Request::setHeader(std::string token, std::string value)
{
	_headers[token] = value;
}

void										Request::setEnvForCgi(std::string token, std::string value)
{
	std::transform(token.begin(), token.end(), token.begin(), ::toupper);
	for (size_t i = 0 ; i < token.size() ; i++)
		if (token[i] == '-')
			token[i] = '_';
	_env_for_cgi["HTTP_" + token] = value;
}

void										Request::setNetwork(std::string IpPort)
{
	std::string	host;
	size_t		colons = IpPort.find(":");

	host = IpPort.substr(0, colons);
	if (host == "localhost")
		_network.host.s_addr = inet_addr("127.0.0.1");
	else if (host.find_first_not_of("0123456789.") != std::string::npos)
		_network.hostName = host.c_str();
	else
		_network.host.s_addr = inet_addr(host.c_str());
	_network.port = std::atoi(IpPort.substr(++colons).c_str());
}

void										Request::setBody(std::string body)
{
	_body = body;
}

void										Request::setHeaders(stringMap headers)
{
	_headers = headers;
}

t_network									Request::getNetwork(void) const
{
	return (_network);
}

int											Request::getPort(void) const
{
	return _port;
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

int					Request::getCode() const
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
	if(_headers.count(str))
		return (_headers[str]);
	else
		return ("");
}

std::string		Request::getQuery(void) const
{
	return (_query);
}
