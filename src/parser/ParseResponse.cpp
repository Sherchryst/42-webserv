/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParseResponse.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 19:44:34 by sgah              #+#    #+#             */
/*   Updated: 2021/12/14 14:34:47 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

Config		Parser::findLocation(Config& server, std::string& locationName)
{
	serverMap locations(server.getLocation());

	if (locationName.empty())
		return server;
	if (locations.empty())
		return server;

	for (serverMap::const_iterator i = locations.begin(); i != locations.end(); i++)
		for (std::string tmp = locationName; tmp.empty(); tmp.resize(tmp.size() - 1))
			if (tmp == i->first)
				return i->second;
	return server;
}

void		Parser::parseResponse(ConfigResponse& confResponse, Request& request, Config& server)
{
	std::string	locationName(request.getPath());
	Config		location(findLocation(server, locationName));

	confResponse.setRequest(request);
	confResponse.setServer(server);
	confResponse.setLocationFile(request.getPath());
	confResponse.setLocationPath(locationName);
	confResponse.setLocation(location);
	confResponse.setErrorMap(location.getErrorPage());
	confResponse.setClientBodyBufferSize(location.getClientBodyBufferSize());
	confResponse.setCgiParam(location.getCgiParam());
	confResponse.setCgiPass(location.getCgiPass());
	confResponse.setAllowMethod(location.getAllowedMethods());
	confResponse.setLanguage(request.getHeader("Accept-Language"));
	confResponse.setAutoIndex(server.getAutoIndex());
	confResponse.setIndex(location.getIndex());

	std::cout << (location.getisAliasSet() ? "YES" : "NO") << std::endl;
	if (location.getisAliasSet())
		confResponse.setContentLocation(location.getRoot() + location.getAlias() + request.getPath());
	else
		confResponse.setContentLocation(location.getRoot() + request.getPath());
}
