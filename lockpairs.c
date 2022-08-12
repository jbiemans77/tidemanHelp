void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        printf("Looping i: %i\n", i);
        for (int x = 0; x < pair_count; x++)
        {
            printf("Looping x: %i\n", x);
            int r = x;
            if (locked[pairs[i].loser][pairs[x].loser] == true)
            {
                printf("Found lock.  i = %i.  x = %i.  [%i][%i]\n", i, x, pairs[i].loser, pairs[x].loser);

                for (int j = 0; j < pair_count; j++)
                {
                    printf("Looping j: %i\n", j);
                    if(locked[pairs[r].loser][pairs[j].loser] == true)
                    {
                        if (pairs[j].loser == pairs[i].winner)
                        {
                            locked[pairs[i].winner][pairs[i].loser] = false;
                            x = pair_count;
                            break;
                        }
                        else
                        {
                            r = j;
                            j = 0;
                        }
                    }
                }
            }
            else
            {
                locked[pairs[i].winner][pairs[i].loser] = true;
                printf("i is %i. x is %i. Locking pair [%i][%i]\n", i, x, pairs[i].winner, pairs[i].loser);
            }
        }
    }
}