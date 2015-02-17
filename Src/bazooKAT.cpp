
int fenetre_bazookat_menus(int x_menus,int y_menus)
{

Rect BazooWBack(Vec2D(x_menus,y_menus),Vec2D(size_x_bazoocat_menus,size_y_bazoocat_menus));
BazooWBack.SetRoundness(15);
BazooWBack.SetLineWidth(triple_epaisseur_ligne_fader);
BazooWBack.Draw(CouleurFond);
if(window_focus_id==W_BAZOOKAT)
{
BazooWBack.DrawOutline(CouleurFader);
}
else
{
BazooWBack.DrawOutline(CouleurLigne);
}


return(0);
}


int do_logical_fenetre_bazookat_menus(int x_menus,int y_menus)
{


return(0);
}

