import { createRequire } from "node:module";
const require = createRequire(import.meta.url);

export const mycal = require("../build/Release/mycal");
