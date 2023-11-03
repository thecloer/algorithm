-- 코드를 입력하세요
SELECT PT_NAME, PT_NO, GEND_CD, AGE, IFNULL(TLNO, "NONE")
FROM patient
WHERE gend_cd = 'W' AND AGE <= 12
ORDER BY AGE DESC, PT_NAME;