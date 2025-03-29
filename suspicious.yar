rule Suspicious_Executable {
    meta:
        description = "Detects the suspicious.exe file and its variants"
        author = "Your Name"
        date = "2025-03-11"
   
    strings:
        $s1 = "malicious_function" wide ascii
        $s2 = "C:\\Windows\\System32\\evil.dll" wide ascii
        $s3 = { E8 ?? ?? ?? ?? 68 65 6C 6C 6F }  // Example hex pattern

    condition:
        any of them
}