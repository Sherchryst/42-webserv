/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:07:48 by sgah              #+#    #+#             */
/*   Updated: 2022/01/17 18:44:13 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

//* C LIBRARY
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/sysmacros.h>

//* C NETWORK
# include <sys/types.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/select.h>
# include <sys/poll.h>
# include <sys/epoll.h>

//* CPP LIBRARY
# include <iostream>
# include <iomanip>
# include <sstream>
# include <cstring>
# include <cstdlib>
# include <limits>
# include <cctype>
# include <fstream>
# include <string>
# include <stdexcept>


//* STANDARD TEMPLATE LIBRARY
# include <map>
# include <set>
# include <vector>
# include <algorithm>
# include <iterator>
# include <list>

//* COLORS
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define CYANBG "\033[46m"
# define BLUE "\033[96m"
# define ORANGEBG "\033[1;44m"
# define PINKBG "\033[1;41m"
# define GREENBG "\033[42m"
# define PURPLEBG "\033[45m"
# define GRAYBG "\033[40m"
# define SET "\033[0m"

// *CLASS
# include "t_network.hpp"

//* SHORTCUT
# define BUFFER_SIZE 4096
# define MAX_EV 4096
# define MAX_CLIENTS 1000
# define CLIENT_TIMEOUT 10
// ^ in seconds ^

# define DEFAULT "pages/default.conf"

# define IS_A_DIRECTORY 2
# define IS_A_FILE 1
# define IS_SOMETHING_ELSE 0

# define stringVector				std::vector<std::string>
# define errorMap					std::map<int, std::string>
# define stringMap					std::map<std::string, std::string>
# define netVector					std::vector<t_network>
# define serverMap					std::map<std::string, Config>
# define confVector					std::vector<Config>
# define parseDirectiveMap			std::map<std::string, void (Parser::*)(Config&, stringVector)>
# define methodMap					std::map<std::string, void (Response::*)(void)>
# define stringIntVectorMap			std::map<std::string, std::vector<int> >
# define pairStringIntVector		std::pair<std::string, std::vector<int> >
# define stringSet					std::set<std::string>
# define pairString					std::pair<std::string, std::string>
