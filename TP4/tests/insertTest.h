#include <string>
#include <list>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <netinet/in.h>

#include "../Vector.h"

using namespace CppUnit;
using namespace std;

//-----------------------------------------------------------------------------

class insertTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(insertTest);
    CPPUNIT_TEST(test1);
    CPPUNIT_TEST(test2);    
    CPPUNIT_TEST(test3);
    CPPUNIT_TEST(test4);
    CPPUNIT_TEST(test5);
    CPPUNIT_TEST_SUITE_END();
    
public:
    void setUp(void);
    void tearDown(void);
    
protected:
    void test1(void);
    void test2(void);
    void test3(void);
    void test4(void);
    void test5(void);
    
private:
    
    Vector *vec;
};

// ------------------------ IMPLEMENTATION ------------------------

void insertTest::test1(void)
{   
    //On essaie d'insérer un élément à un index interdit (inférieur à 0)
    CPPUNIT_ASSERT(vec->insert(-1, "test") == false);
}

void insertTest::test2(void)
{
    CPPUNIT_ASSERT(vec->insert(10, "test") == false); //Impossible, car on essaie d'insérer une valeur pour un index plus grand que le nombre d'élément contenu par le vecteur.
}

void insertTest::test3(void)
{
    CPPUNIT_ASSERT(vec->insert(0, "test") == true);//Devrait insérer un élément à l'index 0. N'entre pas dans le while, car aucun élément à décaler, puiqu'on insère à la fin du vecteur.
}

void insertTest::test4(void)
{
    //On insère des éléments aux index 0, 1 du vecteur.
    vec->insert(0,"test");
    vec->insert(1,"test");
    //Ainsi, il est possible d'insérer un élément à l'index 0 en décalant le contenu à l'index 0.
    CPPUNIT_ASSERT(vec->insert(0, "test") == true);
}

void insertTest::test5(void)
{
      //On insère des éléments aux index 0,1 et 2 du vecteur.
    vec->insert(0,"test");
    vec->insert(1,"test");
    vec->insert(2,"test");
    //Ainsi, il est possible d'insérer un élément à l'index 1 en décalant le contenu à l'index 1. Ici, count != capacity. En effet, count = 3, tandis que capacity = 4. On ne passe donc pas par la fonction expandCapacity().
    CPPUNIT_ASSERT(vec->insert(-1, "test") == false);
}

void insertTest::setUp(void)
{
    vec = new Vector();
}

void insertTest::tearDown(void)
{
    delete vec;
}
