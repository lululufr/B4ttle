//void transform(char * map){

int y = 0;
while(map->map[y]!='\0') {
    switch (map->map[y]) {
        //case '*':
        //    //map->map[y]=125; //herbe type2(fleur)
        //    break;
        case ' ':
            int herbe = rand()%10;
            if (herbe>=1){map->map[y]=1;} //herbe type 1
            else if (herbe<=1){map->map[y]=4;}//herbe type 2 (fleur)
            break;
        case '#':
            map->map[y]= 7; // Barriere Horizontale
            if(map->map[y+map->width]=='#' ){
                map->map[y]=10;
            }else if(map->map[y+1] =='#'&&map->map[y-1]==7||map->map[y-1]==6|| map->map[y-1]==8|| map->map[y-1]==9){
                map->map[y]=7;
            }
            break;
            case '|':
                map->map[y]= 10; //Barriere Verticale
            break;

        case '*':
            map->map[y]= 3; //cailloux
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