#!/bin/bash

while :
do 
    echo '请输入数字'
    read num
    case num in 
    1|2|3|4|5)
           num=0;
    ;;    
    *)
        echo "输入数字是$num"
    ;;
    esac
done
