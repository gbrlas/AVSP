-- lab assignment text --

Predikcija kvalitete programera na temelju source koda, tj. njegovog stila - code stylometry

Ideja:

kod → [feature extraction] → features → [learning model] → kvaliteta programera

Koraci:
Pročitati ideju na http://freedom-to-tinker.com/2015/01/21/anonymous-programmers-can-be-identified-by-analyzing-coding-style/
Pročitati članak https://www.cs.drexel.edu/~ac993/papers/caliskan_deanonymizing.pdf

Pokrenuti alat https://github.com/calaylin/CodeStylometry , proučiti kakav output (kakve feature) izbacuje.
Alternativno, može se koristiti i neki od jednostavnijih alata sa https://en.wikipedia.org/wiki/List_of_tools_for_static_code_analysis#C.2C_C.2B.2B , npr. http://cppcheck.sourceforge.net/
Preuzeti velik broj C++ kodova s nekog online judgea, npr. Codeforces ili Google Code Jam koji su koristili autori alata.
Potražiti korelacije između ratinga programera i featurea koje izbacuje alat i prikazati rezultate npr. tablično ili grafički.
Ekstra zadatak za ambiciozne: koristeći neki alat za strojno učenje, istrenirati model koji predviđa rating ili klasu na temelju featurea koda.

Alternativno:
istražiti neku drugu primjenu code stylometryja ili općenito ekstrakcije informacija iz source koda.
