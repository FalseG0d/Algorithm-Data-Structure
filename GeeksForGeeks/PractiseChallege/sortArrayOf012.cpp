
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

// } Driver Code Ends


void sort012(int a[], int n)
{
    // coode here 
    int map[3]={0,0,0};
    
    for(int i=0;i<n;i++){
        map[a[i]]++;
    }
    
    int itr=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<map[i];j++){
            a[itr++]=i;
        }
    }
    
}