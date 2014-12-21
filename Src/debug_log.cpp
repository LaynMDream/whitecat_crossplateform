#include <debug_log.h>

void debug_log_test_01 ()
{
    if (key[KEY_LCONTROL])
    {
        try
        {
            debug_test = 1;
            debugLoopLog[0].tag = " Test 1 >" ; //fmt_string % " Test 1 >" ;
            debugLoopLog[0].entry = 1 ;
            //debugLoopLog[0].data = fmt_debugTest1 % "Scroll" % mouseScroll.level() % mouseScroll.gain() % mouseScroll.speed() % test_level_i % test_level_f ;
            char tmp[54]="                                                     ";
            sprintf(tmp, fmt_debugTest1, "Scroll", mouseScroll.level(), mouseScroll.gain(), mouseScroll.speed(), test_level_i, test_level_f) ;
            debugLoopLog[0].data = std::string(tmp);
        }
        catch ( const std::exception & e )
        {
            //cerr << e.what();
            debug_test = 101;
            debugLine.tag = " Test 1 >" ; //fmt_string %
            debugLine.entry = 1 ;
            debugLine.data = "Erreur format 1 " ;
            debug_log_addToEventLog(debugLine);
        }
    }

}

void debug_log_test_02 ()
{
    if (key[KEY_LCONTROL])
    {
        try
        {
            debug_test = 2;
            debugLoopLog[1].tag = " Test 2 >" ;
            debugLoopLog[1].entry = 2 ;
            //debugLoopLog[1].data = fmt_debugTest2 % "Roll" % mouseRoll.level() % mouseRoll.gain() % mouseRoll.speed() % test_level_i % test_loop ;
            char tmp[54]="                                                     ";
            sprintf(tmp, fmt_debugTest2, "Roll", mouseRoll.level(), mouseRoll.gain(), mouseRoll.speed(), test_level_i, test_loop) ;
            debugLoopLog[1].data = std::string(tmp);
        }
        catch ( const std::exception & e )
        {
            //cerr << e.what();
            debug_test = 102;
            debugLine.tag =  " Test 2 >" ;
            debugLine.entry = 2 ;
            debugLine.data = "Erreur format 2 " ;
            debug_log_addToEventLog(debugLine);
        }
    }

}

void debug_log_test_03 ()
{
    try
    {
        debug_test = 03;
        debugLoopLog[2].tag =  " Test 3 >" ;
        debugLoopLog[2].entry = 3 ;
        //debugLoopLog[2].data = fmt_debugTest3 % "Roll " % mouseRoll.level() % mouseRoll.gain() % mouseRoll.yield() % mouseRoll.speed() ;
        char tmp[54]="                                                     ";
        sprintf(tmp, fmt_debugTest3, "Roll", mouseRoll.level(), mouseRoll.gain(), mouseRoll.yield(), mouseRoll.speed()) ;
        debugLoopLog[2].data = std::string(tmp);
    }
    catch ( const std::exception & e )
    {
        //cerr << e.what();
        debug_test = 103;
        debugLine.tag =  " Test 3 >" ;
        debugLine.entry = 3 ;
        debugLine.data = "Erreur format 3 " ;
        debug_log_addToEventLog(debugLine);
    }
}

void debug_log_test_04 ()
{
try
        {
            debug_test = 04;
            debugLoopLog[3].tag = " Test 4 >" ;
            debugLoopLog[3].entry = 4 ;
            char tmp[54]="                                                     ";
            sprintf(tmp, fmt_debugTest4, "Right", (mouseClicRight.isDown() ? "Yes":"No"), (mouseClicRight.isDouble() ? "Yes":"No"), (mouseClicRight.isProcessed() ? "Yes":"No"), 0);
            debugLoopLog[3].data = std::string(tmp);
        }
        catch ( const std::exception & e )
        {
            //cerr << e.what();
            debug_test = 104;
            debugLine.tag =  " Test 4 >" ;
            debugLine.entry = 4 ;
            debugLine.data = "Erreur format 4 " ;
            debug_log_addToEventLog(debugLine);
        }
}

void debug_log_test_05 ()
{
try
        {
            debug_test = 05;
            debugLoopLog[4].tag = " Test 5 >" ;
            debugLoopLog[4].entry = 5 ;
            char tmp[54]="                                                     ";
            sprintf(tmp, fmt_debugTest4, "Left", (mouseClicLeft.isDown() ? "Yes":"No"), (mouseClicLeft.isDouble() ? "Yes":"No"), (mouseClicLeft.isProcessed() ? "Yes":"No"), 0);
            debugLoopLog[4].data = std::string(tmp);
        }
        catch ( const std::exception & e )
        {
            //cerr << e.what();
            debug_test = 105;
            debugLine.tag =  " Test 5 >" ;
            debugLine.entry = 5 ;
            debugLine.data = "Erreur format 5 " ;
            debug_log_addToEventLog(debugLine);
        }
}

void debug_log_test_06 ()
{
try
        {
            debug_test = 06;
            debugLoopLog[5].tag =  " Test 6 >" ;
            debugLoopLog[5].entry = 6 ;
            //debugLoopLog[5].data = fmt_debugTest3 % "Scroll " % mouseScroll.level() % mouseScroll.gain() % mouseScroll.yield() % mouseScroll.speed() ;
            char tmp[54]="                                                     ";
            sprintf(tmp, fmt_debugTest3, "Scroll", mouseScroll.level(), mouseScroll.gain(), mouseScroll.yield(), mouseScroll.speed()) ;
            debugLoopLog[5].data = std::string(tmp);
        }
        catch ( const std::exception & e )
        {
            //cerr << e.what();
            debug_test = 106;
            debugLine.tag =  " Test 6 >";
            debugLine.entry = 6 ;
            debugLine.data = "Erreur format 3 ";
            debug_log_addToEventLog(debugLine);
        }
}



void debug_log_main_actions_on_screen()
{
    debugLoopLog[0].tag = " qui a pris en charge >" ; //fmt_string % " Test 1 >" ;
    debugLoopLog[0].entry = 1 ;
    //debugLoopLog[0].data = fmt_debugTest1 % "Scroll" % mouseScroll.level() % mouseScroll.gain() % mouseScroll.speed() % test_level_i % test_level_f ;
    char tmp[54]="                                                     ";
    sprintf(tmp, "-- left %s pending %s  last actor %i", (mouseClicLeft.isDown() ? "true":"false"), (mouseClicLeft.isToBeProcessed() ? "true":"false"), mouseClicLeft.lastActor()) ;
    debugLoopLog[0].data = std::string(tmp);

    debugLoopLog[1].tag = " qui a pris en charge >" ; //fmt_string % " Test 1 >" ;
    debugLoopLog[1].entry = 1 ;
    //debugLoopLog[0].data = fmt_debugTest1 % "Scroll" % mouseScroll.level() % mouseScroll.gain() % mouseScroll.speed() % test_level_i % test_level_f ;
    char tmp2[54]="                                                     ";
    sprintf(tmp2, "-- left %s pending %s  last actor %i", (mouseClicRight.isDown() ? "true":"false"), (mouseClicRight.isToBeProcessed() ? "true":"false"), mouseClicRight.lastActor()) ;
    debugLoopLog[1].data = std::string(tmp2);
}

void debug_log_ticker_full_loop()
{
//test begin montée/descente selon vitesse
    if ((key[KEY_LCONTROL]))
    {
        /* 1ère signature de la fonction :
        - niveau géré avec une variable (float)
        */
        test_level_i = whc_mouseWheel::c_levelSpeedupIncrease(whc_mouseWheel::scroll, test_level_f, 100., 0., 1000.);

        /* 2de signature de la fonction :
        - niveau géré avec une variable (int)
        - besoin d'une seconde variable (int) décompte du nombre de passage dans la boucle
        */
        whc_mouseWheel::c_levelSpeedupIncrease(whc_mouseWheel::roll, test_level_i, 256, -255, 1000);
    }
    else
    {
        test_loop =0;
    }

    /* ====================================================================================================
       --- Loop log ---
       ==================================================================================================== */

    if ((test_watchDebugLoop1==1) or (test_watchDebugLoop2==1))
    {
        debug_log_test_01 ();
    }
    if ((test_watchDebugLoop1==2) or (test_watchDebugLoop2==2))
    {
        debug_log_test_02 ();
    }

    if ((test_watchDebugLoop1==3) or (test_watchDebugLoop2==3))
    {
        debug_log_test_03 ();
    }

    if ((test_watchDebugLoop1==4) or (test_watchDebugLoop2==4))
    {
        debug_log_test_04 ();
    }
    if ((test_watchDebugLoop1==5) or (test_watchDebugLoop2==5))
    {
        debug_log_test_05 ();
    }
    if ((test_watchDebugLoop1==6) or (test_watchDebugLoop2==6))
    {
        debug_log_test_06 ();
    }

    /* ====================================================================================================
       --- Event log ---
       ==================================================================================================== */
    {
        try
        {
            debug_test = 9;
            debugLoopLog[8].tag =  " Test 9 >" ;
            debugLoopLog[8].entry = 9 ;
            //debugLoopLog[5].data = fmt_debugTest5 % (editing_plot_background_window_color_backgrd? "Yes":"No") % mouseWheel.yield % Color_plotfill ;
            char tmp[54]="                                                     ";
            sprintf(tmp, fmt_debugTest5, (editing_plot_background_window_color_backgrd? "Yes":"No"), mouseScroll.yield(), Color_plotfill) ;
            debugLoopLog[8].data = std::string(tmp);
        }
        catch ( const std::exception & e )
        {
            //cerr << e.what();
            debug_test = 109;
            debugLine.tag =  " Test 9 >" ;
            debugLine.entry = 9 ;
            debugLine.data = "Erreur format 9 " ;
            debug_log_addToEventLog(debugLine);
        }
    }

    /*if (mouseClicLeft.isToBeProcessed())
    {
        bool tst = mouseClicLeft.toBeProcessed_isDown_isOverRecSize(680,240,270,40,true); //sur espace de retour d'info : SAVE as/
        if (tst and mouseClicLeft.isDouble())
        {
            debug_test = 07;
            debugLine.data = " LEFT DOUBLE sur save as" ;
        }
        else if (tst)
        {
            debug_test = 17;
            debugLine.data = " LEFT Simple sur save as" ;
        }
        else if (mouseClicLeft.isDouble())
        {
            debug_test = 27;
            debugLine.data = " LEFT DOUBLE en dehors de save as" ;
        }
        else
        {
    		debug_test = 37;
    		debugLine.data = " LEFT Simple en dehors de save as" ;
        }


    	debugLine.tag = " Mouse >" ;
    	debugLine.entry = 0 ;
    	AddToEventLog(debugLine);
    }

    if (mouseClicRight.isToBeProcessed())
    {
        bool tst = mouseClicRight.toBeProcessed_isDown_isOverRecSize(680,240,270,40,true); //sur espace de retour d'info : SAVE as/
        if (tst and mouseClicRight.isDouble())
        {
            debug_test = 8;
            debugLine.data = " RIGHT DOUBLE sur save as" ;
        }
        else if (tst)
        {
            debug_test = 18;
            debugLine.data = " RIGHT Simple sur save as" ;
        }
        else if (mouseClicRight.isDouble())
        {
            debug_test = 28;
            debugLine.data = " RIGHT DOUBLE en dehors de save as" ;
        }
        else
        {
            debug_test = 38;
            debugLine.data = " RIGHT Simple en dehors de save as" ;
        }


    	debugLine.tag = " Mouse >" ;
    	debugLine.entry = 0 ;
    	AddToEventLog(debugLine);
    }*/

}

void debug_log_show_test_log(int x_info,int y_info)
{
    if ((debugEventLog.size()>0) and (show_test_log))
    {

        int xxJournal = x_info + 0 ;
        int yyJournal = y_info + 300 ;
        int xxxJournal = 450 ;
        int yyyJournal = 400 ;

        Rect Journal(Vec2D(xxJournal,yyJournal),Vec2D(xxxJournal,yyyJournal));
        Journal.SetRoundness(5);
        Journal.DrawOutline(CouleurLigne);
        petitchiffre.Print("Event log ( max 30 - order < )",xxJournal+5,yyJournal+12);

        int idx = 0;
        int idxmax = debugEventLog.size();
        if (idxmax > 30)
        {
            idxmax = 30 ; //can't show more than --> to do a windwow with scroll facility .. once mouse basics tested
        }
        int xx = xxJournal+5 ;
        int xxx = 100 ;
        int xxdata  = xx + xxx + 2;
        int yy = yyJournal+16 ;
        int xxxdata = xxxJournal - xxx - 2 - 10;
        int xx_number = xxJournal - 76 ;

        while (idx <= idxmax)
        {
            yy += 12 ;
            try
            {
                debugLine = debugEventLog.at(idx);

                petitchiffre.Print(ToString(debugLine.entry), xx_number, yy, xxx,     RIGHT);
                /*
                petitchiffre.Print(debugLine.tag.str(),       xx,        yy, xxx,     RIGHT);
                petitchiffre.Print(debugLine.data.str(),      xxdata,    yy, xxxdata, LEFT);
                */
                petitchiffre.Print(debugLine.tag,       xx,        yy, xxx,     RIGHT);
                petitchiffre.Print(debugLine.data,      xxdata,    yy, xxxdata, LEFT);
            }
            catch ( const std::exception & e )
            {
                //cerr << e.what();
                petitchiffre.Print(e.what(),       xxdata,        yy, xxx,     RIGHT);
            }
            idx ++;
        }

    }

    //if ((debugEventLogInLoop.size()>0) and (show_test_log))
    if ((debugLoopLog_size>0) and (show_test_log))
    {

        int xxJournal = x_info + 0 ;
        int yyJournal = y_info + 250 ;
        int xxxJournal = 340 ;
        int yyyJournal = 45 ;

        Rect Journal(Vec2D(xxJournal,yyJournal),Vec2D(xxxJournal,yyyJournal));
        Journal.SetRoundness(5);
        Journal.DrawOutline(CouleurLigne);
        petitchiffre.Print("Looping data :",xxJournal+5,yyJournal+12);

        //int idxmax = debugLoopLog.size();
        int idxmax = debugLoopLog_size;
        int idx1 = test_watchDebugLoop1;
        if (idx1 > idxmax)
        {
            idx1 = 0 ; //can't show more than --> to do a windwow with a choice off loop data to watch ... once mouse basics tested
        }
        int idx2 = test_watchDebugLoop2;
        if (idx2 > idxmax)
        {
            idx2 = 0 ; //can't show more than --> to do a windwow with a choice off loop data to watch ... once mouse basics tested
        }

        int xx = xxJournal+5 ;
        int xxx = 20 ;
        int xxdata  = xx + xxx + 2;
        int yy = yyJournal+16 ;
        int xxxdata = xxxJournal - xxx - 2 - 10;

        if (idx1 > 0)
        {
            yy += 12 ;
            idx1--;
            try
            {
                debugLine = debugLoopLog[idx1];

                petitchiffre.Print(ToString(debugLine.entry), xx, yy, xxx,     RIGHT);
                //petitchiffre.Print(debugLine.data.str(),      xxdata,    yy, xxxdata, LEFT);
                petitchiffre.Print(debugLine.data,      xxdata,    yy, xxxdata, LEFT);
            }
            catch ( const std::exception & e )
            {
                //cerr << e.what();
                petitchiffre.Print(ToString(idx1), xx, yy, xxx,     RIGHT);
                petitchiffre.Print(e.what(),      xxdata,    yy, xxxdata, LEFT);
            }
        }
        if (idx2 > 0)
        {
            yy += 12 ;
            idx2--;
            try
            {
                debugLine = debugLoopLog[idx2];

                petitchiffre.Print(ToString(debugLine.entry), xx, yy, xxx,     RIGHT);
                //petitchiffre.Print(debugLine.tag.str(),       xx,        yy, xxx,     RIGHT);
                petitchiffre.Print(debugLine.data,      xxdata,    yy, xxxdata, LEFT);
            }
            catch ( const std::exception & e )
            {
                //cerr << e.what();
                petitchiffre.Print(ToString(idx2), xx, yy, xxx,     RIGHT);
                petitchiffre.Print(e.what(),      xxdata,    yy, xxxdata, LEFT);
            }
        }

    }

}

