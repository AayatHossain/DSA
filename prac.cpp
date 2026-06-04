if(v2 > v1){
    dp1[i][j] = v2;
    dp2[i][j] = true;
}else{
    dp1[i][j] = v1;
  
    if(v2 >= v1 && dp2[i][j-currCost] == true){
        dp2[i][j] = true;
    }
}