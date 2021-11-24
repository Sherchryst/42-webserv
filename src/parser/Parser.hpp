/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:32:31 by sgah              #+#    #+#             */
/*   Updated: 2021/11/22 16:28:07 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "webserv.hpp"

class Parser
{
	public:
		Parser(void);
		Parser(Parser const & src);

		~Parser(void);

		Parser&			operator=(const Parser &rhs);

		void			config(const char *file);


	private:
		stringVector	_configfile;
};


#endif
