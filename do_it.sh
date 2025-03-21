#!/bin/bash
echo "****START TESTS****"
echo ""
for folder in *
do
    if [ -d $folder ]; then
        declare -i index
        index=1
        
        echo "****RUN "$folder"****"
        
        cd $folder && make clean && make
        
        for file in data/*
        do
            echo ""
            echo "****START TEST "$((index))"****"

	        echo "Testing input from: $file"
	        
            echo ""
            echo "----PROGRAM RUN----"
            ./$folder < $file
            return_value=$?
            echo "----PROGRAM END----"
            echo ""
            
            echo "Input is: '"$(cat $file)"'"
            echo "Program Returned: $return_value"
	        
            echo "****END TEST "$((index++))"****"
        done
        
	    echo ""
        echo "****END RUN "$folder"****"
        echo ""

        cd ../
    fi
done
echo "****END TESTS****"
