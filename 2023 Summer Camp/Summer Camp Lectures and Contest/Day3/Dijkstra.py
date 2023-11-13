"""node edge sayısı oku
    2 vektör tanımla
    from_beginning
    from_end

    
    define an INF

    for (every edge):
        v[w,y]
        v[w,x]
    
    priority_queue vector
    from_beginning[0]=0
    from_end[0]=0

    pq.append((0,0))
    while(!pq.empty()){
        current = pq.top().second
        dist = pq.top().first
        pq.pop//pushlefth

        if(dist>from_beginning[current]):
            continue
        for (x ,adj[current]):

            if(from_beginning[current ]+x.first < from_beginning[x.second]):
                from_beginning[x.second] = from_beginning[]
                
        
    }


"""