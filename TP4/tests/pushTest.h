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
#include "../Stack.h"

using namespace CppUnit;
using namespace std;

//-----------------------------------------------------------------------------

class pushTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(pushTest);
    CPPUNIT_TEST(test1);
    CPPUNIT_TEST_SUITE_END();
    
public:
    void setUp(void);
    void tearDown(void);
    
protected:
    void test1(void);
    
private:
    
    Stack *stack;
};

// ------------------------ IMPLEMENTATION ------------------------

void pushTest::test1(void)
{   
    stack->push("test");
    CPPUNIT_ASSERT(stack->top()=="test"); //On vérifie indirectement si "test" a bien été ajouté, car la fonction push() n'a aucune sortie. On utilise donc la fonction top(), afin de vérifier ce qui se trouve sur la pile. On sait que la fonction top() fonctionne, car on l'a testé précédemment.
}

void pushTest::setUp(void)
{
    stack = new Stack();
}

void pushTest::tearDown(void)
{
    delete stack;
}
