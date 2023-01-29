//void transform(char * map){

int y = 0;
while(map->map[y]!='\0') {
    switch (map->map[y]) {
        //case '*':
        //    //map->map[y]=125; //herbe type2(fleur)
        //    break;
        case ' ':
            int herbe = rand()%10;
            if (herbe>1){map->map[y]=12;} //herbe type 1
            else if (herbe<1){map->map[y]=125;}//herbe type 2 (fleur)
            break;
        case '#':
            map->map[y]= 23 +40; // roche pleine
            break;
        case '*':
            map->map[y]= 21; //
            break;
        case 'g':
            map->map[y]=7; //
            break;
        case 'h':
            map->map[y]=8; //
            break;
        case 'i':
            map->map[y]=9; //
            break;
        case 'j':
            map->map[y]=10; //
            break;
        case 'k':
            map->map[y]=11; //
            break;
        case 'l':
            map->map[y]=12; //
            break;
        case 'm':
            map->map[y]=13; //
            break;
        case 'n':
            map->map[y]=14; //
            break;
        case 'o':
            map->map[y]=15; //
            break;
        case 'p':
            map->map[y]=16; //
            break;
        case 'q':
            map->map[y]=17; //
            break;
        case 'r':
            map->map[y]=18; //
            break;
        case 's':
            map->map[y]=19; //
            break;
        case 't':
            map->map[y]=20; //
            break;
        case 'u':
            map->map[y]=21; //
            break;
        case 'v':
            map->map[y]=22; //
            break;
        case 'w':
            map->map[y]=23; //
            break;
        case 'x':
            map->map[y]=24; //
            break;
        case 'y':
            map->map[y]=25; //
            break;
        case 'z':
            map->map[y]=26; //
            break;
        case '1':
            map->map[y]=27; //
            break;
        case '2':
            map->map[y]=28; //
            break;
        case '3':
            map->map[y]=29; //
            break;
        case '4':
            map->map[y]=30; //
            break;
        case '5':
            map->map[y]=31; //
            break;
        case '6':
            map->map[y]=32; //
            break;
        case '7':
            map->map[y]=33; //
            break;
        case '8':
            map->map[y]=34; //
            break;
        case '9':
            map->map[y]=35; //
            break;
        case '&':
            map->map[y]=36; //
            break;
        case '"':
            map->map[y]=38; //
            break;
        case '!':
            map->map[y]=10; //
            break;
        case '(':
            map->map[y]=40; //
            break;
        case '-':
            map->map[y]=41; //
            break;
        case '@':
            map->map[y]= 10 +40*2; //
            break;


}
++y;
}
/*
case '3':
            map->map[y]=29; //
            break;
        case '_':
            map->map[y]=30; //
            break;
        case 'ç':
            map->map[y]=31; //
            break;
        case 'à':
            map->map[y]=32; //
            break;
        case ')':
            map->map[y]=30; //
            break;
        case '=':
            map->map[y]=31; //
            break;
        case '~':
            map->map[y]=32; //
            break;

#{[|`\^@
]},;:!?.

 */