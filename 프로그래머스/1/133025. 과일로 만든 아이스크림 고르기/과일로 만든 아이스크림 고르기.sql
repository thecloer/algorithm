-- 코드를 입력하세요
SELECT FLAVOR
from FIRST_HALF
where TOTAL_ORDER > 3000 and flavor in (
    select FLAVOR
    from ICECREAM_INFO
    where INGREDIENT_TYPE = "fruit_based"
)
order by TOTAL_ORDER desc;

# SELECT I.FLAVOR
# FROM ICECREAM_INFO AS I
# INNER JOIN FIRST_HALF AS F ON I.FLAVOR = F.FLAVOR
# WHERE F.TOTAL_ORDER > 3000 AND I.INGREDIENT_TYPE = 'fruit_based'
# ORDER BY F.TOTAL_ORDER DESC;