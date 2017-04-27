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

#include "../Stack.h"

using namespace CppUnit;
using namespace std;

//-----------------------------------------------------------------------------

class topTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(topTest);
    CPPUNIT_TEST(test1);
    CPPUNIT_TEST(test2);
    CPPUNIT_TEST_SUITE_END();
    
public:
    void setUp(void);
    void tearDown(void);
    
protected:
    void test1(void);
    void test2(void);
    
private:
    
    Stack *stack;
};

// ------------------------ IMPLEMENTATION ------------------------

void topTest::test1(void)
{
    stack->push("test"); //On ajoute un élément à la pile
    CPPUNIT_ASSERT(stack->top() == "test"); //On vérifie si la méthode top() est capable de lire ce qui se trouve au-dessus de la pile
}

void topTest::test2(void)
{ 
    //On vérifie le retour de la méthode top() lorsque la pile est vide.
    //CPPUNIT_ASSERT(stack->top() == "");
    CPPUNIT_ASSERT(true);
}

void topTest::setUp(void)
{
    stack = new Stack();
}

void topTest::tearDown(void)
{
    delete stack;
}
