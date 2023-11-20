#include "parser.h"
#include <gtest/gtest.h>



TEST (URL, FTP_1) {
std::string test1 = "ftp://user:password@host:port";
inGeneralURLs(test1);
ASSERT_TRUE ("ftp" == token.schemes);
ASSERT_TRUE ("user" == token_ftp.user_ftp);
ASSERT_TRUE ("password" == token_ftp.password_ftp);
ASSERT_TRUE ("host" == token_ftp.host_ftp);
ASSERT_TRUE ("port" == token_ftp.port_ftp);
token.schemes.clear();
token.schemes_specific_part.clear();
token_ftp.user_ftp.clear();
token_ftp.password_ftp.clear();
token_ftp.host_ftp.clear();
token_ftp.port_ftp.clear();
token_ftp.url_path_ftp.clear();
token_ftp.type_typecode.clear();
}

TEST (URL, FTP_2) {
std::string test2 = "ftp://user@host:port";
inGeneralURLs(test2);
ASSERT_TRUE ("ftp" == token.schemes);
ASSERT_TRUE ("user" == token_ftp.user_ftp);
ASSERT_TRUE ("host" == token_ftp.host_ftp);
ASSERT_TRUE ("port" == token_ftp.port_ftp);
token.schemes.clear();
token.schemes_specific_part.clear();
token_ftp.user_ftp.clear();
token_ftp.password_ftp.clear();
token_ftp.host_ftp.clear();
token_ftp.port_ftp.clear();
token_ftp.url_path_ftp.clear();
token_ftp.type_typecode.clear();
}

TEST (URL, FTP_3) {
std::string test3 = "ftp://user@host";
inGeneralURLs(test3);
ASSERT_TRUE ("ftp" == token.schemes);
ASSERT_TRUE ("user" == token_ftp.user_ftp);
ASSERT_TRUE ("host" == token_ftp.host_ftp);
token.schemes.clear();
token.schemes_specific_part.clear();
token_ftp.user_ftp.clear();
token_ftp.password_ftp.clear();
token_ftp.host_ftp.clear();
token_ftp.port_ftp.clear();
token_ftp.url_path_ftp.clear();
token_ftp.type_typecode.clear();
}

TEST (URL, FTP_4) {
std::string test4 = "ftp://host";
inGeneralURLs(test4);
ASSERT_TRUE ("ftp" == token.schemes);
ASSERT_TRUE ("host" == token_ftp.host_ftp);
token.schemes.clear();
token.schemes_specific_part.clear();
token_ftp.user_ftp.clear();
token_ftp.password_ftp.clear();
token_ftp.host_ftp.clear();
token_ftp.port_ftp.clear();
token_ftp.url_path_ftp.clear();
token_ftp.type_typecode.clear();
}

TEST (URL, FTP_5) {
std::string test5 = "ftp://user:password@host:port/url_path";
inGeneralURLs(test5);
ASSERT_TRUE ("ftp" == token.schemes);
ASSERT_TRUE ("user" == token_ftp.user_ftp);
ASSERT_TRUE ("password" == token_ftp.password_ftp);
ASSERT_TRUE ("host" == token_ftp.host_ftp);
ASSERT_TRUE ("port" == token_ftp.port_ftp);
ASSERT_TRUE ("url_path" == token_ftp.url_path_ftp);
token.schemes.clear();
token.schemes_specific_part.clear();
token_ftp.user_ftp.clear();
token_ftp.password_ftp.clear();
token_ftp.host_ftp.clear();
token_ftp.port_ftp.clear();
token_ftp.url_path_ftp.clear();
token_ftp.type_typecode.clear();
}

TEST (URL, FTP_6) {
std::string test6 = "ftp://user@host:port/url_path";
inGeneralURLs(test6);
ASSERT_TRUE ("ftp" == token.schemes);
ASSERT_TRUE ("user" == token_ftp.user_ftp);
ASSERT_TRUE ("host" == token_ftp.host_ftp);
ASSERT_TRUE ("port" == token_ftp.port_ftp);
ASSERT_TRUE ("url_path" == token_ftp.url_path_ftp);
token.schemes.clear();
token.schemes_specific_part.clear();
token_ftp.user_ftp.clear();
token_ftp.password_ftp.clear();
token_ftp.host_ftp.clear();
token_ftp.port_ftp.clear();
token_ftp.url_path_ftp.clear();
token_ftp.type_typecode.clear();
}

TEST (URL, FTP_7) {
std::string test7 = "ftp://host:port/url_path";
inGeneralURLs(test7);
ASSERT_TRUE ("ftp" == token.schemes);
ASSERT_TRUE ("host" == token_ftp.host_ftp);
ASSERT_TRUE ("port" == token_ftp.port_ftp);
ASSERT_TRUE ("url_path" == token_ftp.url_path_ftp);
token.schemes.clear();
token.schemes_specific_part.clear();
token_ftp.user_ftp.clear();
token_ftp.password_ftp.clear();
token_ftp.host_ftp.clear();
token_ftp.port_ftp.clear();
token_ftp.url_path_ftp.clear();
token_ftp.type_typecode.clear();
}

TEST (URL, FTP_8) {
std::string test8 = "ftp://host/url_path";
inGeneralURLs(test8);
ASSERT_TRUE ("ftp" == token.schemes);
ASSERT_TRUE ("host" == token_ftp.host_ftp);
ASSERT_TRUE ("url_path" == token_ftp.url_path_ftp);
token.schemes.clear();
token.schemes_specific_part.clear();
token_ftp.user_ftp.clear();
token_ftp.password_ftp.clear();
token_ftp.host_ftp.clear();
token_ftp.port_ftp.clear();
token_ftp.url_path_ftp.clear();
token_ftp.type_typecode.clear();
}

TEST (URL, FTP_9) {
std::string test9 = "ftp://user:password@host:port/url_path;type=typecode";
inGeneralURLs(test9);
ASSERT_TRUE ("ftp" == token.schemes);
ASSERT_TRUE ("user" == token_ftp.user_ftp);
ASSERT_TRUE ("password" == token_ftp.password_ftp);
ASSERT_TRUE ("host" == token_ftp.host_ftp);
ASSERT_TRUE ("port" == token_ftp.port_ftp);
ASSERT_TRUE ("url_path" == token_ftp.url_path_ftp);
ASSERT_TRUE ("type=typecode" == token_ftp.type_typecode);
token.schemes.clear();
token.schemes_specific_part.clear();
token_ftp.user_ftp.clear();
token_ftp.password_ftp.clear();
token_ftp.host_ftp.clear();
token_ftp.port_ftp.clear();
token_ftp.url_path_ftp.clear();
token_ftp.type_typecode.clear();
}

TEST (URL, FTP_10) {
std::string test10 = "ftp://user@host:port/url_path;type=typecode";
inGeneralURLs(test10);
ASSERT_TRUE ("ftp" == token.schemes);
ASSERT_TRUE ("user" == token_ftp.user_ftp);
ASSERT_TRUE ("host" == token_ftp.host_ftp);
ASSERT_TRUE ("port" == token_ftp.port_ftp);
ASSERT_TRUE ("url_path" == token_ftp.url_path_ftp);
ASSERT_TRUE ("type=typecode" == token_ftp.type_typecode);
token.schemes.clear();
token.schemes_specific_part.clear();
token_ftp.user_ftp.clear();
token_ftp.password_ftp.clear();
token_ftp.host_ftp.clear();
token_ftp.port_ftp.clear();
token_ftp.url_path_ftp.clear();
token_ftp.type_typecode.clear();
}

TEST (URL, FTP_11) {
std::string test11 = "ftp://host:port/url_path;type=typecode";
inGeneralURLs(test11);
ASSERT_TRUE ("ftp" == token.schemes);
ASSERT_TRUE ("host" == token_ftp.host_ftp);
ASSERT_TRUE ("port" == token_ftp.port_ftp);
ASSERT_TRUE ("url_path" == token_ftp.url_path_ftp);
ASSERT_TRUE ("type=typecode" == token_ftp.type_typecode);
token.schemes.clear();
token.schemes_specific_part.clear();
token_ftp.user_ftp.clear();
token_ftp.password_ftp.clear();
token_ftp.host_ftp.clear();
token_ftp.port_ftp.clear();
token_ftp.url_path_ftp.clear();
token_ftp.type_typecode.clear();
}

TEST (URL, FTP_12) {
std::string test12 = "ftp://host/url_path;type=typecode";
inGeneralURLs(test12);
ASSERT_TRUE ("ftp" == token.schemes);
ASSERT_TRUE ("host" == token_ftp.host_ftp);
ASSERT_TRUE ("url_path" == token_ftp.url_path_ftp);
ASSERT_TRUE ("type=typecode" == token_ftp.type_typecode);
token.schemes.clear();
token.schemes_specific_part.clear();
token_ftp.user_ftp.clear();
token_ftp.password_ftp.clear();
token_ftp.host_ftp.clear();
token_ftp.port_ftp.clear();
token_ftp.url_path_ftp.clear();
token_ftp.type_typecode.clear();
}

TEST (URL, HTTP_1) {
std::string test1 = "http://host:port/path?searchpart";
inGeneralURLs(test1);
ASSERT_TRUE ("http" == token.schemes);
ASSERT_TRUE ("host" == token_http.host_http);
ASSERT_TRUE ("port" == token_http.port_http);
ASSERT_TRUE ("path" == token_http.path_http);
ASSERT_TRUE ("searchpart" == token_http.searhpart_http);
token.schemes.clear();
token.schemes_specific_part.clear();
token_http.host_http.clear();
token_http.port_http.clear();
token_http.path_http.clear();
token_http.searhpart_http.clear();
}

TEST (URL, HTTP_2) {
std::string test2 = "http://host/path?searchpart";
inGeneralURLs(test2);
ASSERT_TRUE ("http" == token.schemes);
ASSERT_TRUE ("host" == token_http.host_http);
ASSERT_TRUE ("path" == token_http.path_http);
ASSERT_TRUE ("searchpart" == token_http.searhpart_http);
token.schemes.clear();
token.schemes_specific_part.clear();
token_http.host_http.clear();
token_http.port_http.clear();
token_http.path_http.clear();
token_http.searhpart_http.clear();
}

TEST (URL, HTTP_3) {
std::string test3 = "http://host:port";
inGeneralURLs(test3);
ASSERT_TRUE ("http" == token.schemes);
ASSERT_TRUE ("host" == token_http.host_http);
ASSERT_TRUE ("port" == token_http.port_http);
token.schemes.clear();
token.schemes_specific_part.clear();
token_http.host_http.clear();
token_http.port_http.clear();
token_http.path_http.clear();
token_http.searhpart_http.clear();
}

TEST (URL, HTTP_4) {
std::string test4 = "http://host";
inGeneralURLs(test4);
ASSERT_TRUE ("http" == token.schemes);
ASSERT_TRUE ("host" == token_http.host_http);
token.schemes.clear();
token.schemes_specific_part.clear();
token_http.host_http.clear();
token_http.port_http.clear();
token_http.path_http.clear();
token_http.searhpart_http.clear();
}

TEST (URL, TELNET_1) {
std::string test1 = "telnet://user:password@host:port/url_path";
inGeneralURLs(test1);
ASSERT_TRUE ("telnet" == token.schemes);
ASSERT_TRUE ("host" == token_telnet.host_telnet);
ASSERT_TRUE ("port" == token_telnet.port_telnet);
ASSERT_TRUE ("user" == token_telnet.user_telnet);
ASSERT_TRUE ("password" == token_telnet.password_telnet);
ASSERT_TRUE ("url_path" == token_telnet.url_path_telnet);
token.schemes.clear();
token.schemes_specific_part.clear();
token_telnet.host_telnet.clear();
token_telnet.port_telnet.clear();
token_telnet.user_telnet.clear();
token_telnet.password_telnet.clear();
token_telnet.url_path_telnet.clear();
}

TEST (URL, TELNET_2) {
std::string test1 = "telnet://user:password@host:port";
inGeneralURLs(test1);
ASSERT_TRUE ("telnet" == token.schemes);
ASSERT_TRUE ("host" == token_telnet.host_telnet);
ASSERT_TRUE ("port" == token_telnet.port_telnet);
ASSERT_TRUE ("user" == token_telnet.user_telnet);
ASSERT_TRUE ("password" == token_telnet.password_telnet);
token.schemes.clear();
token.schemes_specific_part.clear();
token_telnet.host_telnet.clear();
token_telnet.port_telnet.clear();
token_telnet.user_telnet.clear();
token_telnet.password_telnet.clear();
token_telnet.url_path_telnet.clear();
}

TEST (URL, TELNET_3) {
std::string test1 = "telnet://user@host:port";
inGeneralURLs(test1);
ASSERT_TRUE ("telnet" == token.schemes);
ASSERT_TRUE ("host" == token_telnet.host_telnet);
ASSERT_TRUE ("port" == token_telnet.port_telnet);
ASSERT_TRUE ("user" == token_telnet.user_telnet);
token.schemes.clear();
token.schemes_specific_part.clear();
token_telnet.host_telnet.clear();
token_telnet.port_telnet.clear();
token_telnet.user_telnet.clear();
token_telnet.password_telnet.clear();
token_telnet.url_path_telnet.clear();
}

TEST (URL, TELNET_4) {
std::string test1 = "telnet://user@host";
inGeneralURLs(test1);
ASSERT_TRUE ("telnet" == token.schemes);
ASSERT_TRUE ("host" == token_telnet.host_telnet);
ASSERT_TRUE ("user" == token_telnet.user_telnet);
token.schemes.clear();
token.schemes_specific_part.clear();
token_telnet.host_telnet.clear();
token_telnet.port_telnet.clear();
token_telnet.user_telnet.clear();
token_telnet.password_telnet.clear();
token_telnet.url_path_telnet.clear();
}

TEST (URL, TELNET_5) {
std::string test1 = "telnet://host";
inGeneralURLs(test1);
ASSERT_TRUE ("telnet" == token.schemes);
ASSERT_TRUE ("host" == token_telnet.host_telnet);
token.schemes.clear();
token.schemes_specific_part.clear();
token_telnet.host_telnet.clear();
token_telnet.port_telnet.clear();
token_telnet.user_telnet.clear();
token_telnet.password_telnet.clear();
token_telnet.url_path_telnet.clear();
}

TEST (URL, TELNET_6) {
std::string test1 = "telnet://user@host:port/url_path";
inGeneralURLs(test1);
ASSERT_TRUE ("telnet" == token.schemes);
ASSERT_TRUE ("host" == token_telnet.host_telnet);
ASSERT_TRUE ("port" == token_telnet.port_telnet);
ASSERT_TRUE ("user" == token_telnet.user_telnet);
ASSERT_TRUE ("url_path" == token_telnet.url_path_telnet);
token.schemes.clear();
token.schemes_specific_part.clear();
token_telnet.host_telnet.clear();
token_telnet.port_telnet.clear();
token_telnet.user_telnet.clear();
token_telnet.password_telnet.clear();
token_telnet.url_path_telnet.clear();
}

TEST (URL, TELNET_7) {
std::string test1 = "telnet://host:port/url_path";
inGeneralURLs(test1);
ASSERT_TRUE ("telnet" == token.schemes);
ASSERT_TRUE ("host" == token_telnet.host_telnet);
ASSERT_TRUE ("port" == token_telnet.port_telnet);
ASSERT_TRUE ("url_path" == token_telnet.url_path_telnet);
token.schemes.clear();
token.schemes_specific_part.clear();
token_telnet.host_telnet.clear();
token_telnet.port_telnet.clear();
token_telnet.user_telnet.clear();
token_telnet.password_telnet.clear();
token_telnet.url_path_telnet.clear();
}

TEST (URL, TELNET_8) {
std::string test1 = "telnet://host/url_path";
inGeneralURLs(test1);
ASSERT_TRUE ("telnet" == token.schemes);
ASSERT_TRUE ("host" == token_telnet.host_telnet);
ASSERT_TRUE ("url_path" == token_telnet.url_path_telnet);
token.schemes.clear();
token.schemes_specific_part.clear();
token_telnet.host_telnet.clear();
token_telnet.port_telnet.clear();
token_telnet.user_telnet.clear();
token_telnet.password_telnet.clear();
token_telnet.url_path_telnet.clear();
}

TEST (URL, FILE_1) {
std::string test1 = "file://host/path";
inGeneralURLs(test1);
ASSERT_TRUE ("file" == token.schemes);
ASSERT_TRUE ("host" == token_file.host_file);
ASSERT_TRUE ("path" == token_file.path_file);
token.schemes.clear();
token.schemes_specific_part.clear();
token_file.host_file.clear();
token_file.path_file.clear();
}

TEST (URL, FILE_2) {
std::string test1 = "file://host";
inGeneralURLs(test1);
ASSERT_TRUE ("file" == token.schemes);
ASSERT_TRUE ("host" == token_file.host_file);
token.schemes.clear();
token.schemes_specific_part.clear();
token_file.host_file.clear();
token_file.path_file.clear();
}

TEST (URL, GOPHER_1) {
std::string test1 = "gopher://host:port/gopher_path";
inGeneralURLs(test1);
ASSERT_TRUE ("gopher" == token.schemes);
ASSERT_TRUE ("host" == token_gopher.host_gopher);
ASSERT_TRUE ("port" == token_gopher.port_gopher);
ASSERT_TRUE ("gopher_path" == token_gopher.path_gopher);
token.schemes.clear();
token.schemes_specific_part.clear();
token_gopher.host_gopher.clear();
token_gopher.port_gopher.clear();
token_gopher.path_gopher.clear();
}

TEST (URL, GOPHER_2) {
std::string test1 = "gopher://host/gopher_path";
inGeneralURLs(test1);
ASSERT_TRUE ("gopher" == token.schemes);
ASSERT_TRUE ("host" == token_gopher.host_gopher);
ASSERT_TRUE ("gopher_path" == token_gopher.path_gopher);
token.schemes.clear();
token.schemes_specific_part.clear();
token_gopher.host_gopher.clear();
token_gopher.port_gopher.clear();
token_gopher.path_gopher.clear();
}

TEST (URL, GOPHER_3) {
std::string test1 = "gopher://host";
inGeneralURLs(test1);
ASSERT_TRUE ("gopher" == token.schemes);
ASSERT_TRUE ("host" == token_gopher.host_gopher);
token.schemes.clear();
token.schemes_specific_part.clear();
token_gopher.host_gopher.clear();
token_gopher.port_gopher.clear();
token_gopher.path_gopher.clear();
}

TEST (URL, GOPHER_4) {
std::string test1 = "gopher://host:port";
inGeneralURLs(test1);
ASSERT_TRUE ("gopher" == token.schemes);
ASSERT_TRUE ("host" == token_gopher.host_gopher);
ASSERT_TRUE ("port" == token_gopher.port_gopher);
token.schemes.clear();
token.schemes_specific_part.clear();
token_gopher.host_gopher.clear();
token_gopher.port_gopher.clear();
token_gopher.path_gopher.clear();
}

TEST (URL, NNTP_1) {
std::string test1 = "nntp://host:port/newsgroup_name/article_number";
inGeneralURLs(test1);
ASSERT_TRUE ("nntp" == token.schemes);
ASSERT_TRUE ("host" == token_nntp.host_nntp);
ASSERT_TRUE ("port" == token_nntp.port_nntp);
ASSERT_TRUE ("newsgroup_name" == token_nntp.newsgroup_name_nntp);
ASSERT_TRUE ("article_number" == token_nntp.article_number_nntp);
token.schemes.clear();
token.schemes_specific_part.clear();
token_nntp.host_nntp.clear();
token_nntp.port_nntp.clear();
token_nntp.newsgroup_name_nntp.clear();
token_nntp.article_number_nntp.clear();
}

TEST (URL, NNTP_2) {
std::string test1 = "nntp://host/newsgroup_name/article_number";
inGeneralURLs(test1);
ASSERT_TRUE ("nntp" == token.schemes);
ASSERT_TRUE ("host" == token_nntp.host_nntp);
ASSERT_TRUE ("newsgroup_name" == token_nntp.newsgroup_name_nntp);
ASSERT_TRUE ("article_number" == token_nntp.article_number_nntp);
token.schemes.clear();
token.schemes_specific_part.clear();
token_nntp.host_nntp.clear();
token_nntp.port_nntp.clear();
token_nntp.newsgroup_name_nntp.clear();
token_nntp.article_number_nntp.clear();
}

TEST (URL, NNTP_3) {
std::string test1 = "nntp://host";
inGeneralURLs(test1);
ASSERT_TRUE ("nntp" == token.schemes);
ASSERT_TRUE ("host" == token_nntp.host_nntp);
token.schemes.clear();
token.schemes_specific_part.clear();
token_nntp.host_nntp.clear();
token_nntp.port_nntp.clear();
token_nntp.newsgroup_name_nntp.clear();
token_nntp.article_number_nntp.clear();
}

TEST (URL, NNTP_4) {
std::string test1 = "nntp://host:port";
inGeneralURLs(test1);
ASSERT_TRUE ("nntp" == token.schemes);
ASSERT_TRUE ("host" == token_nntp.host_nntp);
ASSERT_TRUE ("port" == token_nntp.port_nntp);
token.schemes.clear();
token.schemes_specific_part.clear();
token_nntp.host_nntp.clear();
token_nntp.port_nntp.clear();
token_nntp.newsgroup_name_nntp.clear();
token_nntp.article_number_nntp.clear();
}

TEST (URL, NNTP_5) {
std::string test1 = "nntp://host/newsgroup_name";
inGeneralURLs(test1);
ASSERT_TRUE ("nntp" == token.schemes);
ASSERT_TRUE ("host" == token_nntp.host_nntp);
ASSERT_TRUE ("newsgroup_name" == token_nntp.newsgroup_name_nntp);
token.schemes.clear();
token.schemes_specific_part.clear();
token_nntp.host_nntp.clear();
token_nntp.port_nntp.clear();
token_nntp.newsgroup_name_nntp.clear();
token_nntp.article_number_nntp.clear();
}

TEST (URL, PROSPERO_1) {
std::string test1 = "prospero://host:port/hsoname;filed=value";
inGeneralURLs(test1);
ASSERT_TRUE ("prospero" == token.schemes);
ASSERT_TRUE ("host" == token_prospero.host_prospero);
ASSERT_TRUE ("port" == token_prospero.port_prospero);
ASSERT_TRUE ("hsoname" == token_prospero.hsoname_prospero);
ASSERT_TRUE ("filed=value" == token_prospero.field_value);
token.schemes.clear();
token.schemes_specific_part.clear();
token_prospero.host_prospero.clear();
token_prospero.port_prospero.clear();
token_prospero.hsoname_prospero.clear();
token_prospero.field_value.clear();
}

TEST (URL, PROSPERO_2) {
std::string test1 = "prospero://host:port";
inGeneralURLs(test1);
ASSERT_TRUE ("prospero" == token.schemes);
ASSERT_TRUE ("host" == token_prospero.host_prospero);
ASSERT_TRUE ("port" == token_prospero.port_prospero);
token.schemes.clear();
token.schemes_specific_part.clear();
token_prospero.host_prospero.clear();
token_prospero.port_prospero.clear();
token_prospero.hsoname_prospero.clear();
token_prospero.field_value.clear();
}

TEST (URL, PROSPERO_3) {
std::string test1 = "prospero://host";
inGeneralURLs(test1);
ASSERT_TRUE ("prospero" == token.schemes);
ASSERT_TRUE ("host" == token_prospero.host_prospero);
token.schemes.clear();
token.schemes_specific_part.clear();
token_prospero.host_prospero.clear();
token_prospero.port_prospero.clear();
token_prospero.hsoname_prospero.clear();
token_prospero.field_value.clear();
}

TEST (URL, PROSPERO_4) {
std::string test1 = "prospero://host/hsoname;filed=value";
inGeneralURLs(test1);
ASSERT_TRUE ("prospero" == token.schemes);
ASSERT_TRUE ("host" == token_prospero.host_prospero);
ASSERT_TRUE ("hsoname" == token_prospero.hsoname_prospero);
ASSERT_TRUE ("filed=value" == token_prospero.field_value);
token.schemes.clear();
token.schemes_specific_part.clear();
token_prospero.host_prospero.clear();
token_prospero.port_prospero.clear();
token_prospero.hsoname_prospero.clear();
token_prospero.field_value.clear();
}

TEST (URL, PROSPERO_5) {
std::string test1 = "prospero://host/hsoname";
inGeneralURLs(test1);
ASSERT_TRUE ("prospero" == token.schemes);
ASSERT_TRUE ("host" == token_prospero.host_prospero);
ASSERT_TRUE ("hsoname" == token_prospero.hsoname_prospero);
token.schemes.clear();
token.schemes_specific_part.clear();
token_prospero.host_prospero.clear();
token_prospero.port_prospero.clear();
token_prospero.hsoname_prospero.clear();
token_prospero.field_value.clear();
}

TEST (URL, WAIS_1) {
std::string test1 = "wais://host:port/database?search";
inGeneralURLs(test1);
ASSERT_TRUE ("wais" == token.schemes);
ASSERT_TRUE ("host" == token_wais.host_wais);
ASSERT_TRUE ("port" == token_wais.port_wais);
ASSERT_TRUE ("database" == token_wais.database);
ASSERT_TRUE ("search" == token_wais.search_wais);
token.schemes.clear();
token.schemes_specific_part.clear();
token_wais.host_wais.clear();
token_wais.port_wais.clear();
token_wais.database.clear();
token_wais.search_wais.clear();
}

TEST (URL, WAIS_2) {
std::string test1 = "wais://host:port/database";
inGeneralURLs(test1);
ASSERT_TRUE ("wais" == token.schemes);
ASSERT_TRUE ("host" == token_wais.host_wais);
ASSERT_TRUE ("port" == token_wais.port_wais);
ASSERT_TRUE ("database" == token_wais.database);
token.schemes.clear();
token.schemes_specific_part.clear();
token_wais.host_wais.clear();
token_wais.port_wais.clear();
token_wais.database.clear();
token_wais.search_wais.clear();
}

TEST (URL, WAIS_3) {
std::string test1 = "wais://host/database?search";
inGeneralURLs(test1);
ASSERT_TRUE ("wais" == token.schemes);
ASSERT_TRUE ("host" == token_wais.host_wais);
ASSERT_TRUE ("database" == token_wais.database);
ASSERT_TRUE ("search" == token_wais.search_wais);
token.schemes.clear();
token.schemes_specific_part.clear();
token_wais.host_wais.clear();
token_wais.port_wais.clear();
token_wais.database.clear();
token_wais.search_wais.clear();
}

TEST (URL, WAIS_4) {
std::string test1 = "wais://host:port";
inGeneralURLs(test1);
ASSERT_TRUE ("wais" == token.schemes);
ASSERT_TRUE ("host" == token_wais.host_wais);
ASSERT_TRUE ("port" == token_wais.port_wais);
token.schemes.clear();
token.schemes_specific_part.clear();
token_wais.host_wais.clear();
token_wais.port_wais.clear();
token_wais.database.clear();
token_wais.search_wais.clear();
}

TEST (URL, WAIS_5) {
std::string test1 = "wais://host";
inGeneralURLs(test1);
ASSERT_TRUE ("wais" == token.schemes);
ASSERT_TRUE ("host" == token_wais.host_wais);
token.schemes.clear();
token.schemes_specific_part.clear();
token_wais.host_wais.clear();
token_wais.port_wais.clear();
token_wais.database.clear();
token_wais.search_wais.clear();
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
