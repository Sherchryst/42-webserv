/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:32:31 by sgah              #+#    #+#             */
/*   Updated: 2021/12/07 19:15:35 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
# define PARSER_HPP

# include "headers.hpp"
# include "Config.hpp"
# include "Request.hpp"
# include "Response.hpp"

class Parser
{
/**========================================================================
 *                           PARSER
 *========================================================================**/
	public:
		Parser(void);
		Parser(Parser const & src);

		~Parser(void);

		Parser&					operator=(const Parser &rhs);

/**========================================================================
 *                           PARSECONFIG
 *========================================================================**/
	public:
		void					readConf(const char *file);
		void					parseConf(void);
		void					checkDirective(const char * expect, stringVector::iterator* actual);
		void					parseServer(stringVector::iterator* it, Config& server);

		confVector				getConfigServers(void);

	private:
		stringVector			_configfile;
		confVector				_ConfigServers;

	private:
		static parseDirectiveMap	_ParsingMap;
		static parseDirectiveMap	_initParsingMap(void);
	private:
		void					parseRoot(Config& configServer,stringVector opts);
		void					parseAlias(Config& configServer,stringVector opts);
		void					parseIndex(Config& configServer,stringVector opts);
		void					parseNetwork(Config& configServer,stringVector opts);
		void					parseCgiPass(Config& configServer,stringVector opts);
		void					parseCgiParam(Config& configServer,stringVector opts);
		void					parseErrorPage(Config& configServer,stringVector opts);
		void					parseAutoIndex(Config& configServer,stringVector opts);
		void					parseServerName(Config& configServer,stringVector opts);
		void					parseAllowedMethods(Config& configServer,stringVector opts);
		void					parseClientBodyBufferSize(Config& configServer,stringVector opts);

/**========================================================================
 *                           PARSING REQUEST
 *========================================================================**/
	public:
		void						parseRequest(const std::string& request, Request& classRequest);

	private:
		static stringVector			initMethods();
		static stringVector			methods;

	private:
		size_t						splitHeader(const std::string& request, stringVector& hearder);
		void						parseHeader(stringVector& hearder, Request& classRequest);
		void						parseFirstLine(stringVector& header, Request& classRequest);

/**========================================================================
 *                           PARSING RESPONSE
 *========================================================================**/
	public:
		void						parseResponse(Request& request, Response& response, Config& server);
		Config						getLocationServer(Config& server, std::string path, std::string& name);
};


#endif
