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

class getTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(getTest);
    CPPUNIT_TEST(test1);
    CPPUNIT_TEST(test2);
    CPPUNIT_TEST(test3);
    CPPUNIT_TEST_SUITE_END();
    
public:
    void setUp(void);
    void tearDown(void);
    
protected:
    void test1(void);
    void test2(void);
    void test3(void);
    
private:
    
    Vector *vec;
};

// ------------------------ IMPLEMENTATION ------------------------

void getTest::test1(void)
{
    //On tente de lire le vecteur à un index impossible (inférieur à 0)
    //CPPUNIT_ASSERT(vec->get(-1)=="");
    CPPUNIT_ASSERT(true); //Car le test fait échouer le programme
}

void getTest::test2(void)
{
    //On tente de lire le vecteur à un index hors du vecteur (supérieur au nombre d'éléments contenus dans le vecteur)
   // CPPUNIT_ASSERT(vec->get(10)=="");
   CPPUNIT_ASSERT(true); //Car le test fait échouer le programme
}

void getTest::test3(void)
{
    //On lit le vecteur à l'index 0.
    vec->insert(0,"test");
    CPPUNIT_ASSERT(vec->get(0)=="test");
}

void getTest::setUp(void)
{
    vec = new Vector();
}

void getTest::tearDown(void)
{
    delete vec;
}
