cmd_Release/mycal.node := ln -f "Release/obj.target/mycal.node" "Release/mycal.node" 2>/dev/null || (rm -rf "Release/mycal.node" && cp -af "Release/obj.target/mycal.node" "Release/mycal.node")
