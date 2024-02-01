# Counter-based-debounce-algorithm
Not every small fault should immediately generate a DTC and thus trigger the asso-ciated fault reaction. If, for example, the battery voltage is too low for a few seconds, then switching off the ABS is simply an overreaction. For this reason most events are debounced.

After all there are three different strategies, which differ considera-bly in their definition.

Time-based debouncing:
In this case, an error must be present for a certain time in order to become ef-fective as DTC (Confirmed).
Counter-based debouncing:
Here an error counter is incremented with different step sizes up to 127 for “Confirmed” or down to -128 for “Passed”. This way a precisely granular de-bouncing behavior can be modulated.
Internal debouncing:
There is no debouncing by the DM and the monitor delivers already de-bounced events.
