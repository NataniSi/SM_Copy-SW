Here are definitions for the different hardware configurations. Each pcb version has it's own base file, which is the ideal form. Then there are the modified subversions, configurations that appeared due to imperfections.

You may notice that for example the tf-luna(tf-l, tfl) sensor addresses or whether the robot has an external ir module are missing from these files. This design choice was made because we think these values are too volatile and would have to be often changed or overriden.

Another design choice was to have all definitions in the newest base version, with the unused commented out insted of them being deleted like in all other versions. This makes creating new versions easier, because you can just copy the last base version.

When adding new features to newer version, these definitions should be copied to older configs a well for backwards compaibility of configs to main programs.

\- RNS on he12025/04/26