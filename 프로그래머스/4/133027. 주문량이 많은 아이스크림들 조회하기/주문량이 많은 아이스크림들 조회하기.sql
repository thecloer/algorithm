SELECT f.flavor
from first_half as f
left join (
    select flavor, sum(total_order) as tot
    from july
    group by flavor
) j
on f.flavor = j.flavor
order by f.total_order + j.tot desc
limit 3;