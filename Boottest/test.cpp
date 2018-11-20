#define BOOST_TEST_MODULE Simple testcase 
#include <C:/Program Files/boost/include/boost-1_67/boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(suite01)

BOOST_AUTO_TEST_CASE(simple_test00)
{
    BOOST_CHECK(Gethora() == 0);
{
BOOST_AUTO_TEST_CASE(simple_test01)
{
    BOOST_CHECK(GetMinuto() == 0);
}
BOOST_AUTO_TEST_CASE(simple_test02)
{
    BOOST_CHECK(GetSegundo() == 0);
}
BOOST_AUTO_TEST_CASE(simple_test03)
{
    BOOST_CHECK(Horastring() == "00:00:00");
{

BOOST_AUTO_TEST_SUITE_END()

/*
#define  BOOST_TEST_MODULE  custom_main 
#define  BOOST_TEST_NO_MAIN 
#define  BOOST_TEST_ALTERNATIVE_INIT_API 
#include  < boost / teste / incluido / unit_test . hpp > 
#include  < iostream > 
namespace  utf  =  boost :: unit_test ;

BOOST_AUTO_TEST_CASE ( test1 ) 
{ 
  BOOST_TEST ( false ); 
}

void  make_use_of ( char **) 
{ 
  std :: cout  <<  "Usando o ponto de entrada personalizado ..."  <<  std :: endl ; 
}

int  main ( int  argc ,  char *  argv [],  char *  envp []) 
{ 
  make_use_of ( envp ); 
  return  utf :: unit_test_main ( init_unit_test ,  argc ,  argv ); 
}
*/