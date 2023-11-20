#include <iostream>
#include <cstring> 
#include <exception>


void schemesSpecificPartFTP (const std::string&);
void schemesSpecificPartHTTP (const std::string&);
void schemesSpecificPartTELNET (const std::string&);
void schemesSpecificPartFILES (const std::string&);
void schemesSpecificPartGOPHER (const std::string&);
void schemesSpecificPartNNTP (const std::string&);
void schemesSpecificPartPROSPERO (const std::string&);
void schemesSpecificPartWAIS (const std::string&);




struct InGeneralURLs {
    std::string schemes;
    std::string schemes_specific_part;
}token;

enum class StatesGeneralURLs {
    schemes,
    specific_part   
};

struct SpecificPartFTP {
    std::string character_ftp;
    std::string user_ftp;
    std::string password_ftp;
    std::string host_ftp;
    std::string port_ftp;
    std::string url_path_ftp;
    std::string type_typecode;
}token_ftp;

enum class StatesSpecificPartFTP {
    slash_after_scheme1,
    slash_after_scheme2,
    user,
    password,
    host,
    port,
    url_path,
    type_typecode
};

struct SpecificPartHTTP {
    std::string character;
    std::string host_http;
    std::string port_http;
    std::string path_http;
    std::string searhpart_http;
}token_http;

enum class StatesSpecificPartHTTP {
    slash_after_scheme1,
    slash_after_scheme2,
    host,
    port,
    path,
    searchpart
};

struct SpecificPartTELNET {
    std::string character_telnet;
    std::string user_telnet;
    std::string password_telnet;
    std::string host_telnet;
    std::string port_telnet;
    std::string url_path_telnet;
}token_telnet;

enum class StatesSpecificPartTELNET {
    slash_after_scheme1,
    slash_after_scheme2,
    user,
    password,
    host,
    port,
    url_path
};

struct SpecificPartFILES {
    std::string character_file;
    std::string host_file;
    std::string path_file;
}token_file;

enum class StatesSpecificPartFILES {
    slash_after_scheme1,
    slash_after_scheme2,
    host,
    path
};

struct SpecificPartGOPHER {
    std::string character_gopher;
    std::string host_gopher;
    std::string port_gopher;
    std::string path_gopher;
}token_gopher;

enum class StatesSpecificPartGOPHER {
    slash_after_scheme1,
    slash_after_scheme2,
    host,
    port,
    path,
};

struct SpecificPartNNTP {
    std::string character_nntp;
    std::string host_nntp;
    std::string port_nntp;
    std::string newsgroup_name_nntp;
    std::string article_number_nntp;
}token_nntp;

enum class StatesSpecificPartNNTP {
    slash_after_scheme1,
    slash_after_scheme2,
    host,
    port,
    newsgroup,
    article_number
};

struct SpecificPartPROSPERO{
    std::string character_prospero;
    std::string host_prospero;
    std::string port_prospero;
    std::string hsoname_prospero;
    std::string field_value;
}token_prospero;

enum class StatesSpecificPartPROSPERO {
    slash_after_scheme1,
    slash_after_scheme2,
    host,
    port,
    hsoname,
    field_value
};

struct SpecificPartWAIS {
    std::string character_wais;
    std::string host_wais;
    std::string port_wais;
    std::string database;
    std::string search_wais;
}token_wais;

enum class StatesSpecificPartWAIS {
    slash_after_scheme1,
    slash_after_scheme2,
    host,
    port,
    database,
    search
};

void inGeneralURLs (const std::string& url){
    StatesGeneralURLs state = StatesGeneralURLs::schemes;
    for (auto i = 0u; i < url.size(); ++i) {
        char current = url[i];
        switch (state)
	    {
	    case StatesGeneralURLs::schemes:
		if (current != ':') {
			state = StatesGeneralURLs::schemes;
            token.schemes += current;
		}
		else {
			state = StatesGeneralURLs::specific_part;
		}
		break;
        case StatesGeneralURLs::specific_part:
		if (current != '\0') {
			state = StatesGeneralURLs::specific_part;
            token.schemes_specific_part += current;
		}
        break;
        }
    }
    const std::string ftp = "ftp";
    const std::string http = "http";
    const std::string telnet = "telnet";
    const std::string file = "file";
    const std::string gopher = "gopher";
    const std::string nntp = "nntp";
    const std::string prospero = "prospero";
    const std::string wais = "wais";
    const std::string mailto = "mailto";
    const std::string news = "news";
    if (token.schemes == http) {
        schemesSpecificPartHTTP (token.schemes_specific_part);
        std::cout << "Schemes: "<< token.schemes << std::endl;
        std::cout << "Host: " << token_http.host_http << std::endl;
        std::cout << "Port: " << token_http.port_http << std::endl;
        std::cout << "Url_path: "<< token_http.path_http << std::endl;
        std::cout << "Serhpart: "<< token_http.searhpart_http << std::endl;
    } else if (token.schemes == ftp) {
        schemesSpecificPartFTP (token.schemes_specific_part);
        std::cout << "Schemes: "<< token.schemes << std::endl;
        std::cout << "User: "<< token_ftp.user_ftp << std::endl;
        std::cout << "password: " << token_ftp.password_ftp << std::endl;
        std::cout << "host: " << token_ftp.host_ftp << std::endl;
        std::cout << "port: " << token_ftp.port_ftp << std::endl;
        std::cout << "url_path: " << token_ftp.url_path_ftp << std::endl;
        std::cout << "Type=typecode: "  << token_ftp.type_typecode << std::endl;
    } else if (token.schemes == telnet) {
        schemesSpecificPartTELNET (token.schemes_specific_part);
        std::cout << "Schemes: "<< token.schemes << std::endl;
        std::cout << "User: "<< token_telnet.user_telnet << std::endl;
        std::cout << "Password: " << token_telnet.password_telnet << std::endl;
        std::cout << "Host: " << token_telnet.host_telnet << std::endl;
        std::cout << "Port: " << token_telnet.port_telnet << std::endl;
        std::cout << "Url_path: " << token_telnet.url_path_telnet << std::endl;
    } else if (token.schemes == file) {
        schemesSpecificPartFILES (token.schemes_specific_part);
        std::cout << "Schemes: "<< token.schemes << std::endl;
        std::cout << "Host: "<< token_file.host_file << std::endl;
        std::cout << "Path: " << token_file.path_file << std::endl;
    } else if (token.schemes == gopher) {
        schemesSpecificPartGOPHER (token.schemes_specific_part);
        std::cout << "Schemes: "<< token.schemes << std::endl;
        std::cout << "host: " << token_gopher.host_gopher << std::endl;
        std::cout << "port: " << token_gopher.port_gopher << std::endl;
        std::cout << "Gopher-path: " << token_gopher.path_gopher << std::endl;
    } else if (token.schemes == nntp) {
        schemesSpecificPartNNTP (token.schemes_specific_part);
        std::cout << "Schemes: "<< token.schemes << std::endl;
        std::cout << "Host: " << token_nntp.host_nntp<< std::endl;
        std::cout << "Port: " << token_nntp.port_nntp << std::endl;
        std::cout << "Newsgroup-name: " << token_nntp.newsgroup_name_nntp << std::endl;
        std::cout << "Article-number: " << token_nntp.article_number_nntp << std::endl;
    } else if (token.schemes == prospero) {
        schemesSpecificPartPROSPERO (token.schemes_specific_part);
        std::cout << "Schemes: "<< token.schemes << std::endl;
        std::cout << "Host: " << token_prospero.host_prospero<< std::endl;
        std::cout << "Port: " << token_prospero.port_prospero << std::endl;
        std::cout << "Hsoname: " << token_prospero.hsoname_prospero << std::endl;
        std::cout << "Field=value: " << token_prospero.field_value << std::endl;

    } else if (token.schemes == wais) {
        schemesSpecificPartWAIS (token.schemes_specific_part);
        std::cout << "Schemes: "<< token.schemes << std::endl;
        std::cout << "Host: " << token_wais.host_wais<< std::endl;
        std::cout << "Port: " << token_wais.port_wais << std::endl;
        std::cout << "Database: " << token_wais.database << std::endl;
        std::cout << "Search: " << token_wais.search_wais << std::endl;
    } else if (token.schemes == mailto) {
        std::cout << "Shemes: " << token.schemes << std::endl;
        std::cout << "rfs822-addr-spec: " << token.schemes_specific_part << std::endl;
    } else if (token.schemes == news) {
        std::cout << "Shemes: " << token.schemes << std::endl;
        std::cout << "Newsgroup-name or message-id: " << token.schemes_specific_part << std::endl;
    }
}

void schemesSpecificPartFTP (const std::string& url) {
    StatesSpecificPartFTP state = StatesSpecificPartFTP::slash_after_scheme1;
    for (auto i = 0u; i < url.size(); ++i) {
        char current = url[i];
        switch (state)
	    {
	        case StatesSpecificPartFTP::slash_after_scheme1:
            if (current == '/') {
                token_ftp.character_ftp += current;
                state = StatesSpecificPartFTP::slash_after_scheme2;
            }
            if (current != '/') {
                throw std::runtime_error ("required '//' before host");
            }
            break;

            case StatesSpecificPartFTP::slash_after_scheme2:
            if (current == '/') {
                token_ftp.character_ftp += current;
                state = StatesSpecificPartFTP::host;
            }
            if (current != '/') {
                throw std::runtime_error ("required '//' before host");
            }
            break;

            case StatesSpecificPartFTP::host:
            if (current != ':' && current != '/' && current != '@') {
                state = StatesSpecificPartFTP::host;
                token_ftp.host_ftp += current;
            } else if (current == '@') {
                token_ftp.user_ftp = token_ftp.host_ftp;
                token_ftp.host_ftp.clear();
                state = StatesSpecificPartFTP::host;
            } else if (current == ':') {
                state = StatesSpecificPartFTP::port;
            } else if (current == '/') {
                state = StatesSpecificPartFTP::url_path;
            }
            break;

            case StatesSpecificPartFTP::port:
            if (current != '/' && current != '@') {
                state = StatesSpecificPartFTP::port;
                token_ftp.port_ftp += current;
            } else if (current == '/') {
                state = StatesSpecificPartFTP::url_path;
            } else if (current == '@') {
                token_ftp.user_ftp = token_ftp.host_ftp;
                token_ftp.password_ftp = token_ftp.port_ftp;
                token_ftp.host_ftp.clear();
                token_ftp.port_ftp.clear();
                state = StatesSpecificPartFTP::host;
            }
            break;

            case StatesSpecificPartFTP::user:
            if (current != ':' && current != '@' && current != '/') {
                state = StatesSpecificPartFTP::user;
                token_ftp.user_ftp += current;
            } else if (current == ':') {
                state = StatesSpecificPartFTP::password;
            } else if (current == '@') {
                state = StatesSpecificPartFTP::host;
            } else if (current == '/') {
                state = StatesSpecificPartFTP::url_path;
            }
            break;

            case StatesSpecificPartFTP::password:
            if (current != '@' && current != '/') {
                state = StatesSpecificPartFTP::password;
                token_ftp.password_ftp += current;
            } else if (current == '@') {
                state = StatesSpecificPartFTP::host;
            } else if (current == '/') {
                token_ftp.host_ftp = token_ftp.user_ftp;
                token_ftp.port_ftp = token_ftp.password_ftp;
                token_ftp.user_ftp.clear();
                token_ftp.password_ftp.clear();
                state = StatesSpecificPartFTP::url_path;
            }
            break;

            case StatesSpecificPartFTP::url_path:
            if (current != ';') {
                state = StatesSpecificPartFTP::url_path;
                token_ftp.url_path_ftp += current;
            } else if (current == ';') {
                state = StatesSpecificPartFTP::type_typecode;
            }
            break;

            case StatesSpecificPartFTP::type_typecode:
            if (current != '\0') {
                state = StatesSpecificPartFTP::type_typecode;
                token_ftp.type_typecode += current;
            }
            break;
            default:
            break;
        }
    }
    if (token_ftp.host_ftp.empty()) {
        throw std::runtime_error ("host cannot be empty");
    }
    if (token_ftp.port_ftp.empty()) {
        token_ftp.port_ftp = "is omitted, the port defaults to 21";
    }
    if (token_ftp.user_ftp.empty()) {
        token_ftp.user_ftp = "is omitted";
    }
    if (token_ftp.password_ftp.empty()) {
        token_ftp.password_ftp = "is omitted";
    }
    if (token_ftp.url_path_ftp.empty()) {
        token_ftp.url_path_ftp = "is omitted";
    }
    if (token_ftp.type_typecode.empty()) {
        token_ftp.type_typecode = "is omitted";
    }
    
}

void schemesSpecificPartHTTP (const std::string& url) {
    StatesSpecificPartHTTP state = StatesSpecificPartHTTP::slash_after_scheme1;
    for (auto i = 0u; i < url.size(); ++i) {
        char current = url[i];
        switch (state)
        {
            case StatesSpecificPartHTTP::slash_after_scheme1:
            if (current == '/') {
                token_http.character += current;
                state = StatesSpecificPartHTTP::slash_after_scheme2;
            }
            if (current != '/') {
                throw std::runtime_error ("required '//' before host");
            }
            break;

            case StatesSpecificPartHTTP::slash_after_scheme2:
            if (current == '/') {
                token_http.character += current;
                state = StatesSpecificPartHTTP::host;
            }
            if (current != '/') {
                throw std::runtime_error ("required '//' before host");
            }
            break;

            case StatesSpecificPartHTTP::host:
            if (current != ':' && current != '/' && i != '\0') {
                state = StatesSpecificPartHTTP::host;
                token_http.host_http += current;
            } else if (current == ':') {
                state = StatesSpecificPartHTTP::port;
            } else if (current == '/') {
                state = StatesSpecificPartHTTP::path;
            } else if (i != '\0') {
                token_http.host_http += current;
            }
            if (token_http.host_http.empty()) {
                throw std::runtime_error ("host cannot be empty");
            }
            break;

            case StatesSpecificPartHTTP::port:
            if (current != '/') {
                state = StatesSpecificPartHTTP::port;
                token_http.port_http += current;
            } else if (current == '/') {
                state = StatesSpecificPartHTTP::path;
            }
            break;

            case StatesSpecificPartHTTP::path:
            if (current != '?') {
                state = StatesSpecificPartHTTP::path;
                token_http.path_http += current;
            } else if (current == '?') {
                state = StatesSpecificPartHTTP::searchpart;
            }
            break;

            case StatesSpecificPartHTTP::searchpart:
            if (current != '\0') {
                state = StatesSpecificPartHTTP::searchpart;
                token_http.searhpart_http += current;
            }
            break;
            default:
            break;
        }
    }
    if (token_http.host_http.empty()) {
        throw std::runtime_error ("host cannot be empty");
    }
    if (token_http.port_http.empty()) {
        token_http.port_http = "is omitted, the port defaults to 80";
    }
    if (token_http.path_http.empty()) {
        token_http.path_http = "is omitted";
    }
    if (token_http.searhpart_http.empty()) {
        token_http.searhpart_http = "is omitted";
    }
}

void schemesSpecificPartTELNET (const std::string& url) {
    StatesSpecificPartTELNET state = StatesSpecificPartTELNET::slash_after_scheme1;
    for (auto i = 0u; i < url.size(); ++i) {
        char current = url[i];
        switch (state)
	    {
	        case StatesSpecificPartTELNET::slash_after_scheme1:
            if (current == '/') {
                token_telnet.character_telnet += current;
                state = StatesSpecificPartTELNET::slash_after_scheme2;
            }
            if (current != '/') {
                throw std::runtime_error ("required '//' before host");
            }
            break;

            case StatesSpecificPartTELNET::slash_after_scheme2:
            if (current == '/') {
                token_telnet.character_telnet += current;
                state = StatesSpecificPartTELNET::host;
            }
            if (current != '/') {
                throw std::runtime_error ("required '//' before host");
            }
            break;

            case StatesSpecificPartTELNET::host:
            if (current != ':' && current != '/' && current != '@') {
                state = StatesSpecificPartTELNET::host;
                token_telnet.host_telnet += current;
            } else if (current == '@') {
                token_telnet.user_telnet = token_telnet.host_telnet;
                token_telnet.host_telnet.clear();
                state = StatesSpecificPartTELNET::host;
            } else if (current == ':') {
                state = StatesSpecificPartTELNET::port;
            } else if (current == '/') {
                state = StatesSpecificPartTELNET::url_path;
            }
            break;

            case StatesSpecificPartTELNET::port:
            if (current != '/' && current != '@') {
                state = StatesSpecificPartTELNET::port;
                token_telnet.port_telnet += current;
            } else if (current == '/') {
                state = StatesSpecificPartTELNET::url_path;
            } else if (current == '@') {
                token_telnet.user_telnet = token_telnet.host_telnet;
                token_telnet.password_telnet = token_telnet.port_telnet;
                token_telnet.host_telnet.clear();
                token_telnet.port_telnet.clear();
                state = StatesSpecificPartTELNET::host;
            }
            break;

            case StatesSpecificPartTELNET::user:
            if (current != ':' && current != '@' && current != '/') {
                state = StatesSpecificPartTELNET::user;
                token_telnet.user_telnet += current;
            } else if (current == ':') {
                state = StatesSpecificPartTELNET::password;
            } else if (current == '@') {
                state = StatesSpecificPartTELNET::host;
            } else if (current == '/') {
                state = StatesSpecificPartTELNET::url_path;
            }
            break;

            case StatesSpecificPartTELNET::password:
            if (current != '@' && current != '/') {
                state = StatesSpecificPartTELNET::password;
                token_telnet.password_telnet += current;
            } else if (current == '@') {
                state = StatesSpecificPartTELNET::host;
            } else if (current == '/') {
                token_telnet.host_telnet = token_telnet.user_telnet;
                token_telnet.port_telnet = token_telnet.password_telnet;
                token_telnet.user_telnet.clear();
                token_telnet.password_telnet.clear();
                state = StatesSpecificPartTELNET::url_path;
            }
            break;

            case StatesSpecificPartTELNET::url_path:
            if (current != '\0') {
                state = StatesSpecificPartTELNET::url_path;
                token_telnet.url_path_telnet += current;
            }
            break;
            default:
            break;
        }
    }
    if (token_telnet.host_telnet.empty()) {
        throw std::runtime_error ("host cannot be empty");
    }
    if (token_telnet.port_telnet.empty()) {
        token_telnet.port_telnet = "is omitted, the port defaults to 23";
    }
    if (token_telnet.user_telnet.empty()) {
        token_telnet.user_telnet = "is omitted";
    }
    if (token_telnet.password_telnet.empty()) {
        token_telnet.password_telnet = "is omitted";
    }
    if (token_telnet.url_path_telnet.empty()) {
        token_telnet.url_path_telnet = "is omitted";
    }
}
    
void schemesSpecificPartFILES (const std::string& url) {
    StatesSpecificPartFILES state = StatesSpecificPartFILES::slash_after_scheme1;
    for (auto i = 0u; i < url.size(); ++i) {
        char current = url[i];
        switch (state)
        {
            case StatesSpecificPartFILES::slash_after_scheme1:
            if (current == '/') {
                token_file.character_file += current;
                state = StatesSpecificPartFILES::slash_after_scheme2;
            }
            if (current != '/') {
                throw std::runtime_error ("required '//' before host");
            }
            break;

            case StatesSpecificPartFILES::slash_after_scheme2:
            if (current == '/') {
                token_file.character_file += current;
                state = StatesSpecificPartFILES::host;
            }
            if (current != '/') {
                throw std::runtime_error ("required '//' before host");
            }
            break;

            case StatesSpecificPartFILES::host:
            if (current != '/') {
                state = StatesSpecificPartFILES::host;
                token_file.host_file += current;
            } else if (current == '/') {
                state = StatesSpecificPartFILES::path;
            }
            break;

            case StatesSpecificPartFILES::path:
            if (current != '\0') {
                state = StatesSpecificPartFILES::path;
                token_file.path_file += current;
            }
            break;
            default:
            break;

        }
    }
    if (token_file.host_file.empty()) {
        throw std::runtime_error ("host cannot be empty");
    }
    if (token_file.path_file.empty()) {
        token_file.path_file = "is omitted";
    }
}

void schemesSpecificPartGOPHER (const std::string& url) {
    StatesSpecificPartGOPHER state = StatesSpecificPartGOPHER::slash_after_scheme1;
    for (auto i = 0u; i < url.size(); ++i) {
        char current = url[i];
        switch (state)
        {
            case StatesSpecificPartGOPHER::slash_after_scheme1:
            if (current == '/') {
                token_gopher.character_gopher += current;
                state = StatesSpecificPartGOPHER::slash_after_scheme2;
            }
            if (current != '/') {
                throw std::runtime_error ("required '//' before host");
            }
            break;

            case StatesSpecificPartGOPHER::slash_after_scheme2:
            if (current == '/') {
                token_gopher.character_gopher += current;
                state = StatesSpecificPartGOPHER::host;
            }
            if (current != '/') {
                throw std::runtime_error ("required '//' before host");
            }
            break;

            case StatesSpecificPartGOPHER::host:
            if (current != ':' && current != '/' && i != '\0') {
                state = StatesSpecificPartGOPHER::host;
                token_gopher.host_gopher += current;
            } else if (current == ':') {
                state = StatesSpecificPartGOPHER::port;
            } else if (current == '/') {
                state = StatesSpecificPartGOPHER::path;
            } else if (i != '\0') {
                token_gopher.host_gopher += current;
            }
            if (token_gopher.host_gopher.empty()) {
                throw std::runtime_error ("host cannot be empty");
            }
            break;

            case StatesSpecificPartGOPHER::port:
            if (current != '/') {
                state = StatesSpecificPartGOPHER::port;
                token_gopher.port_gopher += current;
            } else if (current == '/') {
                state = StatesSpecificPartGOPHER::path;
            }
            break;

            case StatesSpecificPartGOPHER::path:
            if (current != '\0') {
                state = StatesSpecificPartGOPHER::path;
                token_gopher.path_gopher += current;
            }
            break;
            default:
            break;
        }
    }
    if (token_gopher.host_gopher.empty()) {
        throw std::runtime_error ("host cannot be empty");
    }
    if (token_gopher.port_gopher.empty()) {
        token_gopher.port_gopher = "is omitted, the port defaults to 70";
    }
    if (token_gopher.path_gopher.empty()) {
        token_gopher.path_gopher = "is omitted";
    }
}

void schemesSpecificPartNNTP (const std::string& url) {
    StatesSpecificPartNNTP state = StatesSpecificPartNNTP::slash_after_scheme1;
    for (auto i = 0u; i < url.size(); ++i) {
        char current = url[i];
        switch (state)
        {
            case StatesSpecificPartNNTP::slash_after_scheme1:
            if (current == '/') {
                token_nntp.character_nntp += current;
                state = StatesSpecificPartNNTP::slash_after_scheme2;
            }
            if (current != '/') {
                throw std::runtime_error ("required '//' before host");
            }
            break;

            case StatesSpecificPartNNTP::slash_after_scheme2:
            if (current == '/') {
                token_nntp.character_nntp += current;
                state = StatesSpecificPartNNTP::host;
            }
            if (current != '/') {
                throw std::runtime_error ("required '//' before host");
            }
            break;

            case StatesSpecificPartNNTP::host:
            if (current != ':' && current != '/' && i != '\0') {
                state = StatesSpecificPartNNTP::host;
                token_nntp.host_nntp += current;
            } else if (current == ':') {
                state = StatesSpecificPartNNTP::port;
            } else if (current == '/') {
                state = StatesSpecificPartNNTP::newsgroup;
            } else if (i != '\0') {
                token_nntp.host_nntp += current;
            }
            if (token_nntp.host_nntp.empty()) {
                throw std::runtime_error ("host cannot be empty");
            }
            break;

            case StatesSpecificPartNNTP::port:
            if (current != '/') {
                state = StatesSpecificPartNNTP::port;
                token_nntp.port_nntp += current;
            } else if (current == '/') {
                state = StatesSpecificPartNNTP::newsgroup;
            }
            break;

            case StatesSpecificPartNNTP::newsgroup:
            if (current != '/') {
                state = StatesSpecificPartNNTP::newsgroup;
                token_nntp.newsgroup_name_nntp += current;
            } else if (current == '/') {
                state = StatesSpecificPartNNTP::article_number;
            }
            break;

            case StatesSpecificPartNNTP::article_number:
            if (current != '\0') {
                state = StatesSpecificPartNNTP::article_number;
                token_nntp.article_number_nntp += current;
            }
            break;
            default:
            break;
        }
    }
    if (token_nntp.host_nntp.empty()) {
        throw std::runtime_error ("host cannot be empty");
    }
    if (token_nntp.port_nntp.empty()) {
        token_nntp.port_nntp = "is omitted, the port defaults to 119";
    }
    if (token_nntp.newsgroup_name_nntp.empty()) {
        token_nntp.newsgroup_name_nntp = "is omitted";
    }
    if (token_nntp.article_number_nntp.empty()) {
        token_nntp.article_number_nntp = "is omitted";
    }
}

void schemesSpecificPartPROSPERO (const std::string& url) {
    StatesSpecificPartPROSPERO state = StatesSpecificPartPROSPERO::slash_after_scheme1;
    for (auto i = 0u; i < url.size(); ++i) {
        char current = url[i];
        switch (state)
        {
            case StatesSpecificPartPROSPERO::slash_after_scheme1:
            if (current == '/') {
                token_prospero.character_prospero+= current;
                state = StatesSpecificPartPROSPERO::slash_after_scheme2;
            }
            if (current != '/') {
                throw std::runtime_error ("required '//' before host");
            }
            break;

            case StatesSpecificPartPROSPERO::slash_after_scheme2:
            if (current == '/') {
                token_prospero.character_prospero += current;
                state = StatesSpecificPartPROSPERO::host;
            }
            if (current != '/') {
                throw std::runtime_error ("required '//' before host");
            }
            break;

            case StatesSpecificPartPROSPERO::host:
            if (current != ':' && current != '/' && i != '\0') {
                state = StatesSpecificPartPROSPERO::host;
                token_prospero.host_prospero += current;
            } else if (current == ':') {
                state = StatesSpecificPartPROSPERO::port;
            } else if (current == '/') {
                state = StatesSpecificPartPROSPERO::hsoname;
            } else if (i != '\0') {
                token_prospero.host_prospero += current;
            }
            if (token_prospero.host_prospero.empty()) {
                throw std::runtime_error ("host cannot be empty");
            }
            break;

            case StatesSpecificPartPROSPERO::port:
            if (current != '/') {
                state = StatesSpecificPartPROSPERO::port;
                token_prospero.port_prospero += current;
            } else if (current == '/') {
                state = StatesSpecificPartPROSPERO::hsoname;
            }
            break;

            case StatesSpecificPartPROSPERO::hsoname:
            if (current != ';') {
                state = StatesSpecificPartPROSPERO::hsoname;
                token_prospero.hsoname_prospero += current;
            } else if (current == ';') {
                state = StatesSpecificPartPROSPERO::field_value;
            }
            break;

            case StatesSpecificPartPROSPERO::field_value:
            if (current != '\0') {
                state = StatesSpecificPartPROSPERO::field_value;
                token_prospero.field_value += current;
            }
            break;
            default:
            break;
        }
    }
    if (token_prospero.host_prospero.empty()) {
        throw std::runtime_error ("host cannot be empty");
    }
    if (token_prospero.port_prospero.empty()) {
        token_prospero.port_prospero = "is omitted, the port defaults to 1525";
    }
    if (token_prospero.hsoname_prospero.empty()) {
        token_prospero.hsoname_prospero = "is omitted";
    }
    if (token_prospero.field_value.empty()) {
        token_prospero.field_value= "is omitted";
    }
}

void schemesSpecificPartWAIS (const std::string& url) {
    StatesSpecificPartWAIS state = StatesSpecificPartWAIS::slash_after_scheme1;
    for (auto i = 0u; i < url.size(); ++i) {
        char current = url[i];
        switch (state)
        {
            case StatesSpecificPartWAIS::slash_after_scheme1:
            if (current == '/') {
                token_wais.character_wais += current;
                state = StatesSpecificPartWAIS::slash_after_scheme2;
            }
            if (current != '/') {
                throw std::runtime_error ("required '//' before host");
            }
            break;

            case StatesSpecificPartWAIS::slash_after_scheme2:
            if (current == '/') {
                token_wais.character_wais += current;
                state = StatesSpecificPartWAIS::host;
            }
            if (current != '/') {
                throw std::runtime_error ("required '//' before host");
            }
            break;

            case StatesSpecificPartWAIS::host:
            if (current != ':' && current != '/' && i != '\0') {
                state = StatesSpecificPartWAIS::host;
                token_wais.host_wais += current;
            } else if (current == ':') {
                state = StatesSpecificPartWAIS::port;
            } else if (current == '/') {
                state = StatesSpecificPartWAIS::database;
            } else if (i != '\0') {
                token_wais.host_wais += current;
            }
            if (token_wais.host_wais.empty()) {
                throw std::runtime_error ("host cannot be empty");
            }
            break;

            case StatesSpecificPartWAIS::port:
            if (current != '/') {
                state = StatesSpecificPartWAIS::port;
                token_wais.port_wais += current;
            } else if (current == '/') {
                state = StatesSpecificPartWAIS::database;
            }
            break;

            case StatesSpecificPartWAIS::database:
            if (current != '?') {
                state = StatesSpecificPartWAIS::database;
                token_wais.database += current;
            } else if (current == '?') {
                state = StatesSpecificPartWAIS::search;
            }
            break;

            case StatesSpecificPartWAIS::search:
            if (current != '\0') {
                state = StatesSpecificPartWAIS::search;
                token_wais.search_wais += current;
            }
            break;
            default:
            break;
        }
    }
    if (token_wais.host_wais.empty()) {
        throw std::runtime_error ("host cannot be empty");
    }
    if (token_wais.port_wais.empty()) {
        token_wais.port_wais = "is omitted, the port defaults to 210";
    }
    if (token_wais.database.empty()) {
        token_wais.database = "is omitted";
    }
    if (token_wais.search_wais.empty()) {
        token_wais.search_wais = "is omitted";
    }
}
