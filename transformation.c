//void transform(char * map){

//ce code permet de transformer les chars en des trucs plus sympas pour l'affichage
int y = 0;
while(map->map[y]!='\0') {
    switch (map->map[y]) {
        case '~': //chemin

            map->map[y]=60;

        break;

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
            int cailloux = rand()%10;
            if (cailloux>5){map->map[y]=2;}
            else{map->map[y]=3;}
            break;


        case '-':
                //map->map[y-2] =51;
                map->map[y-1] =52;
                map->map[y]=53;
                map->map[y+1] =54;
                //map->map[y-40] =51;

                //map->map[y-43] =58;
                map->map[y-42] =55;
                map->map[y-41] =56;
                map->map[y-40] =57;
                //map->map[y-43] =58;

            break;
            case 'w':
                map->map[y] =51;
                map->map[y-41] =58;
                break;

            case 'i': //chemin
                map->map[y-1] =21;
                map->map[y]=23;
                map->map[y+1] =22;
            break;

       case '!':
         map->map[y]=65;
           break;

        case '1':
                map->map[y]=12;
        break;

    }
++y;
}