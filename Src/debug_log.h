#ifndef DEBUG_LOG_H_INCLUDED
#define DEBUG_LOG_H_INCLUDED

//sab 22/11/2014 - Debug Log - DEB
 /** \brief Stockage des traces de test (max fixé à 30)
  *
  *
  *
  */
//--
typedef struct whc_log
{
	int entry;
	std::string tag;
	std::string data;
} whc_log;
whc_log debugLine;
std::deque<whc_log> debugEventLog;

whc_log debugLoopLog[10];
int debugLoopLog_size=10;
int test_watchDebugLoop1 = 0; // 1ère  sur 2 lignes de restitution des données dans la boucle principale ==> on indique le numéro de test à suivre (variable màj en ligne de commande)
int test_watchDebugLoop2 = 0; // 2de   sur 2 lignes de restitution des données dans la boucle principale
int debug_test = 0; // pour debug pas à pas

char fmt_debugTest1[40]="%s %i gap %i speed %i niv %i niv.f %f";
char fmt_debugTest2[40]="%s %i gap %i speed %i niv %i loop %i";
char fmt_debugTest3[40]="%s %i gap %i yield %i speed %i";
char fmt_debugTest4[40]="%s Double %s Done  %s time %f";
char fmt_debugTest5[50]="BckGrndButton %s mouseYield %i BckGrndColor %f";
char fmt_string[03]="%s";

int whc_log_count =0;
//-- restitution des traces de test : en ligne de commande --test bascule le bool à true
bool show_test_log = false ;
//sab 22/11/2014 - Debug Log - FIN

//test begin montée/descente accélérée
int test_loop =0 ;
int test_level_i = 0 ;
float test_level_f = 0 ;
float test_speed_f = 0 ;

//sab 20/11/2014 - log dev
void debug_log_addToEventLog(whc_log test_log)
//void AddToEventLog(boost::basic_format<char> tag,boost::basic_format<char> data)
//void AddToEventLog(std::string tag, std::string data)
{
		whc_log_count ++;
		//whc_log test_log;
		test_log.entry = whc_log_count;
		debugEventLog.push_front(test_log);
		if (whc_log_count>99999) {whc_log_count=0;}
		if (debugEventLog.size() > 30)
		{
			debugEventLog.resize(31); // keep only last 30 messages
		}
}


#endif // DEBUG_LOG_H_INCLUDED
