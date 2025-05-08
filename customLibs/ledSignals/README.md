<pre style="line-height:1.217; background-color:#2B2B2B; color:#CCCCCC; font-family:consolas;"><h1>ledSignals.h - docs</h1><!-- lib desc --><div>This lib is for blinking LEDs in a specific way. Usefull for signaling to a user the current status of the device.</div>
<!-- graph --><div><h2>output example graph</h2><div  style="background-color:#1F1F1F;">     <span style="color:#9CDCFE;">A</span>  <span style="color:#9CDCFE;">B</span>       <span style="color:#9CDCFE;">D</span>
    ┼──┼─┼  ┼────────┼
    │  │ │  │        │
    │  │ │  │        │
<span style="color:#9CDCFE;">1</span> ─ ╔══╗ ╔══╗        ╔══╗ ╔══╗        ╔══╗ ╔══╗        ╔══╗ ╔══╗
    ║  ║ ║  ║        ║  ║ ║  ║        ║  ║ ║  ║        ║  ║ ║  ║
<span style="color:#9CDCFE;">0</span> ─ ╝  ╚═╝  ╚════════╝  ╚═╝  ╚════════╝  ╚═╝  ╚════════╝  ╚═╝  ╚════════
    │         │                                                ^        │
    │    <span style="color:#9CDCFE;">C</span>    │                                                <span style="color:#9CDCFE;">F</span>        │
    ┼─────────┼                                                         │
    │                                  <span style="color:#9CDCFE;">E</span>                                │
    ┼───────────────────────────────────────────────────────────────────┼</div>
<span style="color:#9CDCFE;">A</span> - timeBurstOn   - On time of a single flash.
<span style="color:#9CDCFE;">B</span> - timeBurstOff  - Off time of a single flash.
<span style="color:#9CDCFE;">C</span> - cyclesBurst   - Repetetions of the A-B segment. The last B segment is part of the D segment. (2 here)
<span style="color:#9CDCFE;">D</span> - timeSignalOff - Time between the C segments.
<span style="color:#9CDCFE;">E</span> - cyclesSignal  - Repetetions of the C-D segment (4 here).
<span style="color:#9CDCFE;">F</span> - Signal ends here, the last D segment is omitted.</div>
<!-- constructor --><div><h2>constructor</h2><div>- <span style="color:#9CDCFE;">pin</span> - <span style="color:#6A9955;">Gpio with the led</span></div>
<div  style="background-color:#1F1F1F;"><span style="color:#4EC9B0;">ledSignals</span><span style="color:#ABCCCC;">::</span><span style="color:#DCDCAA;">ledSignals</span>(<span style="color:#4EC9B0;">uint8_t</span> <span style="color:#9CDCFE;">pin</span>)</div></div>
<!-- set - simple --><div><h2>set (simple)</h2><div>Set a led to blink in a specific pattern for n cycles. All time related values are in ms.

note: Last off pulse is always omitted, both in a single burst and in the whole signal.

 - <span style="color:#9CDCFE;">force</span> - <span style="color:#6A9955;">Whether to force the new signal if the old one is still running.</span>
 - <span style="color:#9CDCFE;">timeBurstOn</span> - <span style="color:#6A9955;">How long should the led stay on each burst.</span>
 - <span style="color:#9CDCFE;">timeBurstOff</span> - <span style="color:#6A9955;">How long should the led stay off each burst.</span>
 - <span style="color:#9CDCFE;">cyclesBurst</span> - <span style="color:#6A9955;">Number of flashes in a burst.</span></div>
<div  style="background-color:#1F1F1F;"><span style="color:#368CCB;">void</span> <span style="color:#4EC9B0;">ledSignals</span><span style="color:#ABCCCC;">::</span><span style="color:#DCDCAA;">set</span>(<span style="color:#569CD6;">bool</span> <span style="color:#9CDCFE;">force</span>, <span style="color:#4EC9B0;">uint16_t</span> <span style="color:#9CDCFE;">timeBurstOn</span>, <span style="color:#4EC9B0;">uint16_t</span> <span style="color:#9CDCFE;">timeBurstOff</span>, <span style="color:#4EC9B0;">uint8_t</span> <span style="color:#9CDCFE;">cyclesBurst</span>)</div></div>
<!-- set - advanced --><div><h2>set (advanced)</h2><div>Set a led to blink in a specific pattern for n cycles. All time related values are in ms.

note: Last off pulse is always omitted, both in a single burst and in the whole signal. Each burs can be max 65s.

 - <span style="color:#9CDCFE;">force</span> - <span style="color:#6A9955;">Whether to force the new signal if the old one is still running.</span>
 - <span style="color:#9CDCFE;">timeBurstOn</span> - <span style="color:#6A9955;">How long should the led stay on each burst.</span>
 - <span style="color:#9CDCFE;">timeBurstOff</span> - <span style="color:#6A9955;">How long should the led stay off each burst.</span>
 - <span style="color:#9CDCFE;">cyclesBurst</span> - <span style="color:#6A9955;">Number of flashes in a burst.</span>
 - <span style="color:#9CDCFE;">timeSignalOff</span> - <span style="color:#6A9955;">How long should the led stay off between each burst.</span>
 - <span style="color:#9CDCFE;">cyclesSignal</span> - <span style="color:#6A9955;">Number of bursts.</span></div>
<div  style="background-color:#1F1F1F;"><span style="color:#368CCB;">void</span> <span style="color:#4EC9B0;">ledSignals</span><span style="color:#ABCCCC;">::</span><span style="color:#DCDCAA;">set</span>(<span style="color:#569CD6;">bool</span> <span style="color:#9CDCFE;">force</span>, <span style="color:#4EC9B0;">uint16_t</span> <span style="color:#9CDCFE;">timeBurstOn</span>, <span style="color:#4EC9B0;">uint16_t</span> <span style="color:#9CDCFE;">timeBurstOff</span>, <span style="color:#4EC9B0;">uint8_t</span> <span style="color:#9CDCFE;">cyclesBurst</span>, <span style="color:#4EC9B0;">uint16_t</span> <span style="color:#9CDCFE;">timeSignalOff</span>, <span style="color:#4EC9B0;">uint8_t</span> <span style="color:#9CDCFE;">cyclesSignal</span>)</div></div>
<!-- loop --><div><h2>loop</h2><div>Updates the output and stuff. Trigger this as often a practical.</div>
<div  style="background-color:#1F1F1F;"><span style="color:#368CCB;">void</span> <span style="color:#4EC9B0;">ledSignals</span><span style="color:#ABCCCC;">::</span><span style="color:#DCDCAA;">loop</span>()</div></div>
<!--  --><div><h2>stop</h2><div>Ends the signal early.</div>
<div  style="background-color:#1F1F1F;"><span style="color:#368CCB;">void</span> <span style="color:#4EC9B0;">ledSignals</span><span style="color:#ABCCCC;">::</span><span style="color:#DCDCAA;">stop</span>()</div></div>
</pre>
