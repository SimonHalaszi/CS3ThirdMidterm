/*

Notions
- push and pull implementation methods

{Studied in Observer}

NOTES:

* push and pull implementation methods {Studied in Observer}
    - Subject needs to communicate state change information to observers

    - There is two types of communication to accomplish this
        - Push - State change is in message itself
            - May require a large message (Say maybe an entire copy of this object)
            
            - Not all concrete observers need all the data

        - Pull - Observer queries the sate of subject after receiving message
            - Observer needs to keep reference to subject

            - Subject needs to implement getters to return state values

    (Actual implementation will be in Observer)
*/